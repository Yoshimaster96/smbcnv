smbcnv: objparse/objparse.c config/config.c frmt/lz.c frmt/extmath.c main.c
	gcc -g -o main main.c frmt/extmath.c frmt/lz.c config/config.c objparse/objparse.c -std=c99 -lm
