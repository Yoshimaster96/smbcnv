#include <stdio.h>

int main()
{
	FILE * raw = fopen("output.lz.raw","rb");
	FILE * fp = fopen("output.lz.raw.lzs","rb");
	FILE * out = fopen("output.lz","wb");
	fseek(raw,0,SEEK_END);
	int usize = ftell(raw);
	fclose(raw);
	int csize = 8+getc(fp)+(getc(fp)<<8)+(getc(fp)<<16)+(getc(fp)<<24);
	putc(csize&0xFF,out);
	putc((csize>>8)&0xFF,out);
	putc((csize>>16)&0xFF,out);
	putc((csize>>24)&0xFF,out);
	putc(usize&0xFF,out);
	putc((usize>>8)&0xFF,out);
	putc((usize>>16)&0xFF,out);
	putc((usize>>24)&0xFF,out);
	for(int i=0; i<(csize-8); i++) {putc(getc(fp),out);}
	fclose(fp);
	fclose(out);
	return 0;
}
