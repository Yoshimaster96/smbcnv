#include "pngparse.h"

image parsePng(char * pngpath)
{
	FILE * png = fopen(pngpath,"rb");
	image returnValue;
	png_structp pngstruct = png_create_read_struct(PNG_LIBPNG_VER_STRING,NULL,NULL,NULL);
	png_infop info = png_create_info_struct(pngstruct);
	png_init_io(pngstruct,png);
	png_read_info(pngstruct,info);
	returnValue.width = png_get_image_width(pngstruct,info);
	returnValue.height = png_get_image_height(pngstruct,info);
	int color_type = png_get_color_type(pngstruct,info);
	int bit_depth = png_get_bit_depth(pngstruct,info);
	if(bit_depth == 16) png_set_strip_16(pngstruct);
	if(color_type == PNG_COLOR_TYPE_PALETTE) png_set_palette_to_rgb(pngstruct);
	if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8) png_set_expand_gray_1_2_4_to_8(pngstruct);
	if(color_type == PNG_COLOR_TYPE_RGB || color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_PALETTE) png_set_filter(pngstruct,0xFF,PNG_FILLER_AFTER);
	if(color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA) png_set_gray_to_rgb(pngstruct);
	png_read_update_info(pngstruct,info);
	png_bytep * row_pointers = (png_bytep*)malloc(sizeof(png_bytep)*returnValue.height);
	for(int y=0; y<returnValue.height; y++) {row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(pngstruct,info));}
	png_read_image(pngstruct,row_pointers);
	fclose(png);
	for(int y=0; y<returnValue.height; y++)
	{
		png_bytep row = row_pointers[y];
		for(int x=0; x<returnValue.width; x++)
		{
			png_bytep px = &(row[x*4]);
			returnValue.pixels[x+(y*returnValue.width)].r = px[0];
			returnValue.pixels[x+(y*returnValue.width)].g = px[1];
			returnValue.pixels[x+(y*returnValue.width)].b = px[2];
			returnValue.pixels[x+(y*returnValue.width)].a = px[3];
		}
	}
	png_destroy_read_struct(&pngstruct,&info,NULL);
	pngstruct=NULL;
	info=NULL;
	return returnValue;
}


