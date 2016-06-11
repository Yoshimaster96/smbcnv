smbcnv: objparse/objparse.c pngparse/pngparse.c frmt/gma.c frmt/tpl.c frmt/lz.c main.c
	gcc -g -o main main.c frmt/lz.c frmt/tpl.c frmt/gma.c pngparse/pngparse.c objparse/objparse.c -std=c99 -lm -lpng
