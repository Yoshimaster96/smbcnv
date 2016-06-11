#include "tpl.h"
#include "../objparse/objparse.h"
#include "../pngparse/pngparse.h"

int textureSizes[256];
int textureWidths[256];
int textureHeights[256];
int textureMipmaps[256];
int min(int a,int b) {return (a<b)?a:b;}

void writeTpl()
{
	for(int i=0; i<tallyMtls; i++)
	{
		char tempfn[80];
		sprintf(tempfn,"./temp/temp%d.tpl.part",i);
		FILE * temp = fopen(tempfn,"wb");
		image textureImage = parsePng(cmnMtls[i].texname);
		int mipmapMinDimension = min(textureImage.width,textureImage.height);
		int mipmapLevel = 1;
		while(mipmapMinDimension>1)
		{
			mipmapMinDimension >>= 1;
			mipmapLevel += 1;
		}
		textureWidths[i] = textureImage.width;
		textureHeights[i] = textureImage.height;
		textureMipmaps[i] = mipmapLevel;
		for(int j=0; j<mipmapLevel; j++)
		{
			for(int y=0; y<textureImage.height>>j; y+=4)
			{
				for(int x=0; x<textureImage.width>>j; x+=4)
				{
					for(int k=0; k<16; k++)
					{
						int xinc = k%4, yinc = k/4;
						int red=0, green=0, blue=0, alpha=0;
						if(((x+xinc)<<j)>textureImage.width || ((y+yinc)<<j)>textureImage.height) {red=0; green=0; blue=0; alpha=0;}
						else
						{
							red = textureImage.pixels[(x+xinc)<<j+(((y+yinc)<<j)*textureImage.width)].r;
							green = textureImage.pixels[(x+xinc)<<j+(((y+yinc)<<j)*textureImage.width)].g;
							blue = textureImage.pixels[(x+xinc)<<j+(((y+yinc)<<j)*textureImage.width)].b;
							alpha = textureImage.pixels[(x+xinc)<<j+(((y+yinc)<<j)*textureImage.width)].a;
							putc(red,temp);
							putc(green,temp);
							putc(blue,temp);
							putc(alpha,temp);
						}
					}
				}
			}
		}
		int size = ftell(temp);
		int paddingSize = 16-(size%16);
		for(int j=0; j<paddingSize; j++) putc(0,temp);
		textureSizes[i] = ftell(temp);
		fclose(temp);
	}
	FILE * tpl = fopen("./temp/output.tpl","wb");
	putc((tallyMtls>>24)&0xFF,tpl);
	putc((tallyMtls>>16)&0xFF,tpl);
	putc((tallyMtls>>8)&0xFF,tpl);
	putc(tallyMtls&0xFF,tpl);
	for(int i=0; i<tallyMtls; i++)
	{
		putc(0,tpl);
		putc(0,tpl);
		putc(0,tpl);
		putc(6,tpl);
		int textureOffset = 16+(16*tallyMtls);
		if(i!=0)
		{
			for(int j=0; j<i-1; j++)
			{
				textureOffset += textureSizes[j];
			}
		}
		putc((textureOffset>>24)&0xFF,tpl);
		putc((textureOffset>>16)&0xFF,tpl);
		putc((textureOffset>>8)&0xFF,tpl);
		putc(textureOffset&0xFF,tpl);
		putc((textureWidths[i]>>8)&0xFF,tpl);
		putc(textureWidths[i]&0xFF,tpl);
		putc((textureHeights[i]>>8)&0xFF,tpl);
		putc(textureHeights[i]&0xFF,tpl);
		putc((textureMipmaps[i]>>8)&0xFF,tpl);
		putc(textureMipmaps[i]&0xFF,tpl);
		putc(0x12,tpl);
		putc(0x34,tpl);
	}
	putc(0,tpl);
	putc(0,tpl);
	putc(0,tpl);
	putc(0,tpl);
	putc(0,tpl);
	putc(0,tpl);
	putc(0,tpl);
	putc(0,tpl);
	putc(0,tpl);
	putc(0,tpl);
	putc(0,tpl);
	putc(0,tpl);
	for(int i=0; i<tallyMtls; i++)
	{
		char tempfn[80];
		sprintf(tempfn,"./temp/temp%d.tpl.part",i);
		FILE * temp = fopen(tempfn,"rb");
		for(int j=0; j<textureSizes[i]; j++) putc(getc(temp),tpl);
		fclose(temp);
	}
	fclose(tpl);
}
