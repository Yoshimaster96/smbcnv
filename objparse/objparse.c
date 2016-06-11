#include "objparse.h"

int tallyVertices = 0;
int tallyTexCoords = 0;
int tallyNormals = 0;
int tallyObjs = 0;
int tallyTris = 0;
int tallyMtls = 0;
int errCount = 0;

void parseObj(char * objpath)
{
	FILE * obj = fopen(objpath,"r");
	char line[80];
	char ident[80];
	char param1[80];
	char param2[80];
	char param3[80];
	while(fgets(line,80,obj)!=NULL)
	{
		sscanf(line," %s ",ident);
		if(strcmp(ident,"v")==0) // Vertex identifier
		{
			sscanf(line," %s %s %s %s ",ident,param1,param2,param3);
			sscanf(param1,"%f",&cmnVertices.vs[tallyVertices].x);
			sscanf(param2,"%f",&cmnVertices.vs[tallyVertices].y);
			sscanf(param3,"%f",&cmnVertices.vs[tallyVertices].z);
			tallyVertices++;
		}
		else if(strcmp(ident,"vt")==0) // TexCoord identifier
		{
			sscanf(line," %s %s %s ",ident,param1,param2);
			sscanf(param1,"%f",&cmnTexCoords.vts[tallyTexCoords].x);
			sscanf(param2,"%f",&cmnTexCoords.vts[tallyTexCoords].y);
			tallyTexCoords++;
		}
		else if(strcmp(ident,"vn")==0) // Normal identifier
		{
			sscanf(line," %s %s %s %s ",ident,param1,param2,param3);
			sscanf(param1,"%f",&cmnNormals.vns[tallyNormals].x);
			sscanf(param2,"%f",&cmnNormals.vns[tallyNormals].y);
			sscanf(param3,"%f",&cmnNormals.vns[tallyNormals].z);
			tallyNormals++;
		}
		else if(strcmp(ident,"f")==0) // Face identifier
		{
			sscanf(line," %s %s %s %s ",ident,param1,param2,param3);
			sscanf(param1,"%i/%i/%i",&cmnObjs[tallyObjs-1].tris[tallyTris].va,&cmnObjs[tallyObjs-1].tris[tallyTris].vta,&cmnObjs[tallyObjs-1].tris[tallyTris].vna);
			sscanf(param2,"%i/%i/%i",&cmnObjs[tallyObjs-1].tris[tallyTris].vb,&cmnObjs[tallyObjs-1].tris[tallyTris].vtb,&cmnObjs[tallyObjs-1].tris[tallyTris].vnb);
			sscanf(param3,"%i/%i/%i",&cmnObjs[tallyObjs-1].tris[tallyTris].vc,&cmnObjs[tallyObjs-1].tris[tallyTris].vtc,&cmnObjs[tallyObjs-1].tris[tallyTris].vnc);
			tallyTris++;
		}
		else if(strcmp(ident,"mtllib")==0) // MTL include identifier
		{
			sscanf(line," %s %s ",ident,param1);
			FILE * mtl = fopen(param1,"r");
			while(feof(mtl)==0)
			{
				char line2[80];
				char ident2[80];
				char params2[80];
				fgets(line2,80,mtl);
				sscanf(line2," %s %s ",ident2,params2);
				if(strcmp(ident2,"newmtl")==0) // Material definition identifier
				{
					sscanf(params2," %s ",cmnMtls[tallyMtls].mtlname);
				}
				else if(strcmp(ident2,"map_Kd")==0) // Include image texture identifier
				{
					sscanf(params2," %s ",cmnMtls[tallyMtls].texname);
					tallyMtls++;
				}
				else if(strcmp(ident2,"#")==0); // Comment identifier
				else {printf("Syntax error in %s:\n %s %s\n",param1,ident2,params2); errCount++;}
				for(int i=0; i<80; i++)
				{
					line2[i] = '\0';
					ident2[i] = '\0';
					params2[i] = '\0';
				}
			}
		}
		else if(strcmp(ident,"usemtl")==0) // MTL usage identifier
		{
			sscanf(line," %s %s ",ident,param1);
			sscanf(param1," %s ",cmnObjs[tallyObjs].mat);
			tallyObjs++;
		}
		else if(strcmp(ident,"#")==0); // Comment identifier
		else {sscanf(line," %s %s ",ident,param1); printf("Syntax error in %s:\n %s %s\n",objpath,ident,param1); errCount++;}
		for(int i=0; i<80; i++)
		{
			line[i] = '\0';
			ident[i] = '\0';
			param1[i] = '\0';
			param2[i] = '\0';
			param3[i] = '\0';
		}
	}
	if(errCount!=0)
	{
		printf("There were %i syntax errors, output file may not be good.\n",errCount);
	}
}
