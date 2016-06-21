#include "objparse/objparse.h"
#include "pngparse/pngparse.h"
#include "config/config.h"
#include "frmt/gma.h"
#include "frmt/tpl.h"
#include "frmt/lz.h"

int main(int argc, char ** argv)
{
	if(argc < 3) printf("Usage:\nsmbcnv [obj file] [config file]\n");
	else
	{
		printf("Parsing OBJ file...\n");
		parseObj(argv[1]);
		printf("Writing GMA file...\n");
		writeGma();
		printf("Writing TPL file...\n");
		writeTpl();
		printf("Parsing config file...\n");
		parseConfig(argv[2]);
		printf("Writing LZ file...\n");
		writeLz();
		printf("Compressing LZ file...\n");
		compressLz();
		printf("Done!\n");
	}
}
