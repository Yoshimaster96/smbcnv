smbcnv: objparse/objparse.c pngparse/pngparse.c config/config.c frmt/gma.c frmt/tpl.c frmt/lz.c frmt/extmath.c main.c
	gcc -g -o main main.c frmt/extmath.c frmt/lz.c frmt/tpl.c frmt/gma.c config/config.c pngparse/pngparse.c objparse/objparse.c -std=c99 -lm -lpng
