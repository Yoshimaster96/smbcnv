#include "objparse.h"

int tallyVertices = 0;
int tallyTexCoords = 0;
int tallyNormals = 0;
int tallyObjs = 1;
int tallyObjNames = 0;
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
			sscanf(param1,"%i/%i/%i",&cmnObjs[tallyObjs-1].tris[tallyTris[tallyObjs-1]].va,&cmnObjs[tallyObjs-1].tris[tallyTris[tallyObjs-1]].vta,&cmnObjs[tallyObjs-1].tris[tallyTris[tallyObjs-1]].vna);
			sscanf(param2,"%i/%i/%i",&cmnObjs[tallyObjs-1].tris[tallyTris[tallyObjs-1]].vb,&cmnObjs[tallyObjs-1].tris[tallyTris[tallyObjs-1]].vtb,&cmnObjs[tallyObjs-1].tris[tallyTris[tallyObjs-1]].vnb);
			sscanf(param3,"%i/%i/%i",&cmnObjs[tallyObjs-1].tris[tallyTris[tallyObjs-1]].vc,&cmnObjs[tallyObjs-1].tris[tallyTris[tallyObjs-1]].vtc,&cmnObjs[tallyObjs-1].tris[tallyTris[tallyObjs-1]].vnc);
			tallyTris[tallyObjs-1]++;
		}
		else if(strcmp(ident,"o")==0) // Object name identifier
		{
			sscanf(line," %s %s ",ident,param1);
			sscanf(param1," %s ",cmnObjNames[tallyObjNames].name);
			tallyObjNames++;
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
