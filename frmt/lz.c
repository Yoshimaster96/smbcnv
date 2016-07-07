#include "lz.h"
#include "extmath.h"
#include "../objparse/objparse.h"
#include "../config/config.h"

void writeLz()
{
	//Write object data
	FILE * temp = fopen("./temp/tempcfg.lz.raw.part","wb");
	int sectOffs[4];
	sectOffs[0]=256;
	for(int i=0; i<goalCount; i++)
	{
		int posx = toInt(goals[i].posx);
		int posy = toInt(goals[i].posy);
		int posz = toInt(goals[i].posz);
		int rotx = cnvAngle(goals[i].rotx);
		int roty = cnvAngle(goals[i].roty);
		int rotz = cnvAngle(goals[i].rotz);
		int type = (goals[i].type==2?('R'<<8):(goals[i].type==1?('G'<<8):('B'<<8)));
		putc((posx>>24)&0xFF,temp);
		putc((posx>>16)&0xFF,temp);
		putc((posx>>8)&0xFF,temp);
		putc(posx&0xFF,temp);
		putc((posy>>24)&0xFF,temp);
		putc((posy>>16)&0xFF,temp);
		putc((posy>>8)&0xFF,temp);
		putc(posy&0xFF,temp);
		putc((posz>>24)&0xFF,temp);
		putc((posz>>16)&0xFF,temp);
		putc((posz>>8)&0xFF,temp);
		putc(posz&0xFF,temp);
		putc((rotx>>8)&0xFF,temp);
		putc(rotx&0xFF,temp);
		putc((roty>>8)&0xFF,temp);
		putc(roty&0xFF,temp);
		putc((rotz>>8)&0xFF,temp);
		putc(rotz&0xFF,temp);
		putc((type>>8)&0xFF,temp);
		putc(type&0xFF,temp);
	}
	sectOffs[1]=ftell(temp)+256;
	for(int i=0; i<bumperCount; i++)
	{
		int posx = toInt(bumpers[i].posx);
		int posy = toInt(bumpers[i].posy);
		int posz = toInt(bumpers[i].posz);
		int rotx = cnvAngle(bumpers[i].rotx);
		int roty = cnvAngle(bumpers[i].roty);
		int rotz = cnvAngle(bumpers[i].rotz);
		int sclx = toInt(bumpers[i].sclx);
		int scly = toInt(bumpers[i].scly);
		int sclz = toInt(bumpers[i].sclz);
		putc((posx>>24)&0xFF,temp);
		putc((posx>>16)&0xFF,temp);
		putc((posx>>8)&0xFF,temp);
		putc(posx&0xFF,temp);
		putc((posy>>24)&0xFF,temp);
		putc((posy>>16)&0xFF,temp);
		putc((posy>>8)&0xFF,temp);
		putc(posy&0xFF,temp);
		putc((posz>>24)&0xFF,temp);
		putc((posz>>16)&0xFF,temp);
		putc((posz>>8)&0xFF,temp);
		putc(posz&0xFF,temp);
		putc((rotx>>8)&0xFF,temp);
		putc(rotx&0xFF,temp);
		putc((roty>>8)&0xFF,temp);
		putc(roty&0xFF,temp);
		putc((rotz>>8)&0xFF,temp);
		putc(rotz&0xFF,temp);
		putc(0,temp);
		putc(0,temp);
		putc((sclx>>24)&0xFF,temp);
		putc((sclx>>16)&0xFF,temp);
		putc((sclx>>8)&0xFF,temp);
		putc(sclx&0xFF,temp);
		putc((scly>>24)&0xFF,temp);
		putc((scly>>16)&0xFF,temp);
		putc((scly>>8)&0xFF,temp);
		putc(scly&0xFF,temp);
		putc((sclz>>24)&0xFF,temp);
		putc((sclz>>16)&0xFF,temp);
		putc((sclz>>8)&0xFF,temp);
		putc(sclz&0xFF,temp);
	}
	sectOffs[2]=ftell(temp)+256;
	for(int i=0; i<jamabarCount; i++)
	{
		int posx = toInt(jamabars[i].posx);
		int posy = toInt(jamabars[i].posy);
		int posz = toInt(jamabars[i].posz);
		int rotx = cnvAngle(jamabars[i].rotx);
		int roty = cnvAngle(jamabars[i].roty);
		int rotz = cnvAngle(jamabars[i].rotz);
		int sclx = toInt(jamabars[i].sclx);
		int scly = toInt(jamabars[i].scly);
		int sclz = toInt(jamabars[i].sclz);
		putc((posx>>24)&0xFF,temp);
		putc((posx>>16)&0xFF,temp);
		putc((posx>>8)&0xFF,temp);
		putc(posx&0xFF,temp);
		putc((posy>>24)&0xFF,temp);
		putc((posy>>16)&0xFF,temp);
		putc((posy>>8)&0xFF,temp);
		putc(posy&0xFF,temp);
		putc((posz>>24)&0xFF,temp);
		putc((posz>>16)&0xFF,temp);
		putc((posz>>8)&0xFF,temp);
		putc(posz&0xFF,temp);
		putc((rotx>>8)&0xFF,temp);
		putc(rotx&0xFF,temp);
		putc((roty>>8)&0xFF,temp);
		putc(roty&0xFF,temp);
		putc((rotz>>8)&0xFF,temp);
		putc(rotz&0xFF,temp);
		putc(0,temp);
		putc(0,temp);
		putc((sclx>>24)&0xFF,temp);
		putc((sclx>>16)&0xFF,temp);
		putc((sclx>>8)&0xFF,temp);
		putc(sclx&0xFF,temp);
		putc((scly>>24)&0xFF,temp);
		putc((scly>>16)&0xFF,temp);
		putc((scly>>8)&0xFF,temp);
		putc(scly&0xFF,temp);
		putc((sclz>>24)&0xFF,temp);
		putc((sclz>>16)&0xFF,temp);
		putc((sclz>>8)&0xFF,temp);
		putc(sclz&0xFF,temp);
	}
	sectOffs[3]=ftell(temp)+256;
	for(int i=0; i<bananaCount; i++)
	{
		int posx = toInt(bananas[i].posx);
		int posy = toInt(bananas[i].posy);
		int posz = toInt(bananas[i].posz);
		int type = bananas[i].type;
		putc((posx>>24)&0xFF,temp);
		putc((posx>>16)&0xFF,temp);
		putc((posx>>8)&0xFF,temp);
		putc(posx&0xFF,temp);
		putc((posy>>24)&0xFF,temp);
		putc((posy>>16)&0xFF,temp);
		putc((posy>>8)&0xFF,temp);
		putc(posy&0xFF,temp);
		putc((posz>>24)&0xFF,temp);
		putc((posz>>16)&0xFF,temp);
		putc((posz>>8)&0xFF,temp);
		putc(posz&0xFF,temp);
		putc((type>>24)&0xFF,temp);
		putc((type>>16)&0xFF,temp);
		putc((type>>8)&0xFF,temp);
		putc(type&0xFF,temp);
	}
	fclose(temp);
	//Write collision triangles
	temp = fopen("./temp/tempcol.lz.raw.part","wb");
	for(int i=0; i<tallyObjs; i++)
	{
		for(int j=0; j<tallyTris[i]; j++)
		{
			vec3 na = {cmnVertices.vs[cmnObjs[i].tris[j].vna-1].x,cmnVertices.vs[cmnObjs[i].tris[j].vna-1].y,cmnVertices.vs[cmnObjs[i].tris[j].vna-1].z};
			vec3 a = {cmnVertices.vs[cmnObjs[i].tris[j].va-1].x,cmnVertices.vs[cmnObjs[i].tris[j].va-1].y,cmnVertices.vs[cmnObjs[i].tris[j].va-1].z};
			vec3 b = {cmnVertices.vs[cmnObjs[i].tris[j].vb-1].x,cmnVertices.vs[cmnObjs[i].tris[j].vb-1].y,cmnVertices.vs[cmnObjs[i].tris[j].vb-1].z};
			vec3 c = {cmnVertices.vs[cmnObjs[i].tris[j].vc-1].x,cmnVertices.vs[cmnObjs[i].tris[j].vc-1].y,cmnVertices.vs[cmnObjs[i].tris[j].vc-1].z};
			vec3 ba = {b.x-a.x,b.y-a.y,b.z-a.z};
			vec3 ca = {c.x-a.x,c.y-a.y,c.z-a.z};
			vec3 normal = normalize(cross(normalize(ba),normalize(ca)));
			float dottest = dot(na,normal);
			if(dottest<0.0)
			{
				normal = normalize(cross(normalize(ca),normalize(ba)));
			}
			float l = sqrtf(normal.x*normal.x + normal.z*normal.z);
			float cy = normal.z/l;
			float sy = normal.x/l;
			if(fabs(l)<0.001)
			{
				cy = 1.0;
				sy = 0.0;
			}
			float cx = l;
			float sx = -normal.y;
			vec3 Rxr0 = {1.0,0.0,0.0};
			vec3 Rxr1 = {0.0,cx,sx};
			vec3 Rxr2 = {0.0,-sx,cx};
			vec3 Ryr0 = {cy,0.0,-sy};
			vec3 Ryr1 = {0.0,1.0,0.0};
			vec3 Ryr2 = {sy,0.0,cy};
			vec3 dotry = dotm(ba,Ryr0,Ryr1,Ryr2);
			vec3 dotrxry = dotm(dotry,Rxr0,Rxr1,Rxr2);
			l = sqrtf(dotrxry.x*dotrxry.x + dotrxry.y*dotrxry.y);
			float cz = dotrxry.x/l;
			float sz = dotrxry.y/l;
			vec3 Rzr0 = {cz,sz,0.0};
			vec3 Rzr1 = {-sz,cz,0.0};
			vec3 Rzr2 = {0.0,0.0,1.0};
			vec3 dotrz = dotm(dotrxry,Rzr0,Rzr1,Rzr2);
			dotry = dotm(ca,Ryr0,Ryr1,Ryr2);
			dotrxry = dotm(dotry,Rxr0,Rxr1,Rxr2);
			vec3 dotrzrxry = dotm(dotrxry,Rzr0,Rzr1,Rzr2);
			vec3 n0v = {dotrzrxry.x-dotrz.x,dotrzrxry.y-dotrz.y,dotrzrxry.z-dotrz.z};
			vec3 n1v = {-dotrzrxry.x,-dotrzrxry.y,-dotrzrxry.z};
			vec3 n0 = normalize(hat(n0v));
			vec3 n1 = normalize(hat(n1v));
			float rot_x = reverse_angle(cx,sx);
			float rot_y = reverse_angle(cy,sy);
			float rot_z = reverse_angle(cz,sz);
			int putMe = toInt(a.x);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(a.y);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(a.z);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(normal.x);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(normal.y);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(normal.z);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = cnvAngle(rot_x);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = cnvAngle(rot_y);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = cnvAngle(rot_z);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putc(0,temp);
			putc(0,temp);
			putMe = toInt(dotrz.x);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(dotrz.y);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(dotrzrxry.x);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(dotrzrxry.y);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(n0.x);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(n0.y);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(n1.x);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(n1.y);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
		}
	}
	fclose(temp);
	//Write complete (uncompressed) file
	FILE * fpCfg = fopen("./temp/tempcfg.lz.raw.part","rb");
	FILE * fpCol = fopen("./temp/tempcol.lz.raw.part","rb");
	temp = fopen("./temp/output.lz.raw","wb");
	fseek(fpCfg,0,SEEK_END);
	int cfgSize = ftell(fpCfg);
	rewind(fpCfg);
	fseek(fpCol,0,SEEK_END);
	int colSize = ftell(fpCol);
	rewind(fpCol);
	int realColSize = colSize + 0xB8 + (0x200*(colSize/0x40)) + 0x600;
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(1,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(100,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(1,temp);
	putc(((cfgSize+256)>>24)&0xFF,temp);
	putc(((cfgSize+256)>>16)&0xFF,temp);
	putc(((cfgSize+256)>>8)&0xFF,temp);
	putc((cfgSize+256)&0xFF,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(160,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(180,temp);
	if(goalCount)
	{
		putc((goalCount>>24)&0xFF,temp);
		putc((goalCount>>16)&0xFF,temp);
		putc((goalCount>>8)&0xFF,temp);
		putc(goalCount&0xFF,temp);
		putc((sectOffs[0]>>24)&0xFF,temp);
		putc((sectOffs[0]>>16)&0xFF,temp);
		putc((sectOffs[0]>>8)&0xFF,temp);
		putc(sectOffs[0]&0xFF,temp);
		putc((goalCount>>24)&0xFF,temp);
		putc((goalCount>>16)&0xFF,temp);
		putc((goalCount>>8)&0xFF,temp);
		putc(goalCount&0xFF,temp);
	}
	else
	{
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
	}
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	if(bumperCount)
	{
		putc((bumperCount>>24)&0xFF,temp);
		putc((bumperCount>>16)&0xFF,temp);
		putc((bumperCount>>8)&0xFF,temp);
		putc(bumperCount&0xFF,temp);
		putc((sectOffs[1]>>24)&0xFF,temp);
		putc((sectOffs[1]>>16)&0xFF,temp);
		putc((sectOffs[1]>>8)&0xFF,temp);
		putc(sectOffs[1]&0xFF,temp);
	}
	else
	{
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
	}
	if(jamabarCount)
	{
		putc((jamabarCount>>24)&0xFF,temp);
		putc((jamabarCount>>16)&0xFF,temp);
		putc((jamabarCount>>8)&0xFF,temp);
		putc(jamabarCount&0xFF,temp);
		putc((sectOffs[2]>>24)&0xFF,temp);
		putc((sectOffs[2]>>16)&0xFF,temp);
		putc((sectOffs[2]>>8)&0xFF,temp);
		putc(sectOffs[2]&0xFF,temp);
	}
	else
	{
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
	}
	if(bananaCount)
	{
		putc((bananaCount>>24)&0xFF,temp);
		putc((bananaCount>>16)&0xFF,temp);
		putc((bananaCount>>8)&0xFF,temp);
		putc(bananaCount&0xFF,temp);
		putc((sectOffs[3]>>24)&0xFF,temp);
		putc((sectOffs[3]>>16)&0xFF,temp);
		putc((sectOffs[3]>>8)&0xFF,temp);
		putc(sectOffs[3]&0xFF,temp);
	}
	else
	{
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
	}
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc((tallyObjNames>>24)&0xFF,temp);
	putc((tallyObjNames>>16)&0xFF,temp);
	putc((tallyObjNames>>8)&0xFF,temp);
	putc(tallyObjNames&0xFF,temp);
	putc(((realColSize+cfgSize+256)>>24)&0xFF,temp);
	putc(((realColSize+cfgSize+256)>>16)&0xFF,temp);
	putc(((realColSize+cfgSize+256)>>8)&0xFF,temp);
	putc((realColSize+cfgSize+256)&0xFF,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	int posx = toInt(starts[0].posx);
	int posy = toInt(starts[0].posy);
	int posz = toInt(starts[0].posz);
	int rotx = cnvAngle(starts[0].rotx);
	int roty = cnvAngle(starts[0].roty);
	int rotz = cnvAngle(starts[0].rotz);
	putc((posx>>24)&0xFF,temp);
	putc((posx>>16)&0xFF,temp);
	putc((posx>>8)&0xFF,temp);
	putc(posx&0xFF,temp);
	putc((posy>>24)&0xFF,temp);
	putc((posy>>16)&0xFF,temp);
	putc((posy>>8)&0xFF,temp);
	putc(posy&0xFF,temp);
	putc((posz>>24)&0xFF,temp);
	putc((posz>>16)&0xFF,temp);
	putc((posz>>8)&0xFF,temp);
	putc(posz&0xFF,temp);
	putc((rotx>>8)&0xFF,temp);
	putc(rotx&0xFF,temp);
	putc((roty>>8)&0xFF,temp);
	putc(roty&0xFF,temp);
	putc((rotz>>8)&0xFF,temp);
	putc(rotz&0xFF,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0xC3,temp);
	putc(0x80,temp);
	putc(0,temp);
	putc(0,temp);
	putc(((12+(tallyObjNames*12)+realColSize+cfgSize+256)>>24)&0xFF,temp);
	putc(((12+(tallyObjNames*12)+realColSize+cfgSize+256)>>16)&0xFF,temp);
	putc(((12+(tallyObjNames*12)+realColSize+cfgSize+256)>>8)&0xFF,temp);
	putc((12+(tallyObjNames*12)+realColSize+cfgSize+256)&0xFF,temp);
	putc(((4+(tallyObjNames*12)+realColSize+cfgSize+256)>>24)&0xFF,temp);
	putc(((4+(tallyObjNames*12)+realColSize+cfgSize+256)>>16)&0xFF,temp);
	putc(((4+(tallyObjNames*12)+realColSize+cfgSize+256)>>8)&0xFF,temp);
	putc((4+(tallyObjNames*12)+realColSize+cfgSize+256)&0xFF,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	for(int i=0; i<cfgSize; i++)
	{
		putc(getc(fpCfg),temp);
	}
	fclose(fpCfg);
	int whereAreWe = ftell(temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0xB8,temp);
	putc(((whereAreWe+0xB8)>>24)&0xFF,temp);
	putc(((whereAreWe+0xB8)>>16)&0xFF,temp);
	putc(((whereAreWe+0xB8)>>8)&0xFF,temp);
	putc((whereAreWe+0xB8)&0xFF,temp);
	putc(((whereAreWe+0x2B8+colSize+(0x200*(colSize/0x40)))>>24)&0xFF,temp);
	putc(((whereAreWe+0x2B8+colSize+(0x200*(colSize/0x40)))>>16)&0xFF,temp);
	putc(((whereAreWe+0x2B8+colSize+(0x200*(colSize/0x40)))>>8)&0xFF,temp);
	putc((whereAreWe+0x2B8+colSize+(0x200*(colSize/0x40)))&0xFF,temp);
	putc(0xC3,temp);
	putc(0x80,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0xC3,temp);
	putc(0x80,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0x42,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0x42,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(16,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(16,temp);
	if(goalCount)
	{
		putc((goalCount>>24)&0xFF,temp);
		putc((goalCount>>16)&0xFF,temp);
		putc((goalCount>>8)&0xFF,temp);
		putc(goalCount&0xFF,temp);
		putc((sectOffs[0]>>24)&0xFF,temp);
		putc((sectOffs[0]>>16)&0xFF,temp);
		putc((sectOffs[0]>>8)&0xFF,temp);
		putc(sectOffs[0]&0xFF,temp);
	}
	else
	{
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
	}
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	if(bumperCount)
	{
		putc((bumperCount>>24)&0xFF,temp);
		putc((bumperCount>>16)&0xFF,temp);
		putc((bumperCount>>8)&0xFF,temp);
		putc(bumperCount&0xFF,temp);
		putc((sectOffs[1]>>24)&0xFF,temp);
		putc((sectOffs[1]>>16)&0xFF,temp);
		putc((sectOffs[1]>>8)&0xFF,temp);
		putc(sectOffs[1]&0xFF,temp);
	}
	else
	{
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
	}
	if(jamabarCount)
	{
		putc((jamabarCount>>24)&0xFF,temp);
		putc((jamabarCount>>16)&0xFF,temp);
		putc((jamabarCount>>8)&0xFF,temp);
		putc(jamabarCount&0xFF,temp);
		putc((sectOffs[2]>>24)&0xFF,temp);
		putc((sectOffs[2]>>16)&0xFF,temp);
		putc((sectOffs[2]>>8)&0xFF,temp);
		putc(sectOffs[2]&0xFF,temp);
	}
	else
	{
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
	}
	if(bananaCount)
	{
		putc((bananaCount>>24)&0xFF,temp);
		putc((bananaCount>>16)&0xFF,temp);
		putc((bananaCount>>8)&0xFF,temp);
		putc(bananaCount&0xFF,temp);
		putc((sectOffs[3]>>24)&0xFF,temp);
		putc((sectOffs[3]>>16)&0xFF,temp);
		putc((sectOffs[3]>>8)&0xFF,temp);
		putc(sectOffs[3]&0xFF,temp);
	}
	else
	{
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
	}
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc((tallyObjNames>>24)&0xFF,temp);
	putc((tallyObjNames>>16)&0xFF,temp);
	putc((tallyObjNames>>8)&0xFF,temp);
	putc(tallyObjNames&0xFF,temp);
	putc(((realColSize+cfgSize+256)>>24)&0xFF,temp);
	putc(((realColSize+cfgSize+256)>>16)&0xFF,temp);
	putc(((realColSize+cfgSize+256)>>8)&0xFF,temp);
	putc((realColSize+cfgSize+256)&0xFF,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	for(int i=0; i<colSize; i++)
	{
		putc(getc(fpCol),temp);
	}
	fclose(fpCol);
	whereAreWe = ftell(temp);
	for(int i=0; i<256; i++)
	{
		for(int j=0; j<(colSize/64); j++)
		{
			putc((j>>8)&0xFF,temp);
			putc(j&0xFF,temp);
		}
		putc(0xFF,temp);
		putc(0xFF,temp);
	}
	for(int i=0; i<256; i++)
	{
		putc(((whereAreWe+i*2+(i*2*(colSize/0x40)))>>24)&0xFF,temp);
		putc(((whereAreWe+i*2+(i*2*(colSize/0x40)))>>16)&0xFF,temp);
		putc(((whereAreWe+i*2+(i*2*(colSize/0x40)))>>8)&0xFF,temp);
		putc((whereAreWe+i*2+(i*2*(colSize/0x40)))&0xFF,temp);
	}
	whereAreWe = ftell(temp);
	for(int i=0; i<tallyObjNames; i++)
	{
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(1,temp);
		putc(((whereAreWe+24+(92*i))>>24)&0xFF,temp);
		putc(((whereAreWe+24+(92*i))>>16)&0xFF,temp);
		putc(((whereAreWe+24+(92*i))>>8)&0xFF,temp);
		putc((whereAreWe+24+(92*i))&0xFF,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
	}
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc('n',temp);
	putc('u',temp);
	putc('l',temp);
	putc('l',temp);
	putc('2',temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	for(int i=0; i<tallyObjNames; i++)
	{
		for(int j=0; j<80; j++)
		{
			putc(cmnObjNames[i].name[j],temp);
		}
	}
	if(ftell(temp)%8 == 4)
	{
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
	}
	fclose(temp);
}
