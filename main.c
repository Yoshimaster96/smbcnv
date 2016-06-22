#include "objparse/objparse.h"
#include "config/config.h"
#include "frmt/lz.h"

int main(int argc, char ** argv)
{
	if(argc < 3) printf("Usage:\nsmbcnv [obj file] [config file]\n");
	else
	{
		printf("Parsing OBJ file...\n");
		parseObj(argv[1]);
		printf("Parsing config file...\n");
		parseConfig(argv[2]);
		printf("Writing LZ file...\n");
		writeLz();
		printf("Compressing LZ file...\n");
		compressLz();
		printf("Done!\n");
	}
}
