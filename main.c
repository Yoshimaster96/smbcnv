#include "objparse/objparse.h"
#include "pngparse/pngparse.h"
#include "frmt/gma.h"
#include "frmt/tpl.h"
#include "frmt/lz.h"

int main(int argc, char ** argv)
{
	if(argc < 2) printf("Usage:\nsmbcnv [obj file]\n");
	else
	{
		printf("Parsing OBJ file...\n");
		parseObj(argv[1]);
		printf("Writing GMA file...\n");
		writeGma();
		printf("Writing TPL file...\n");
		writeTpl();
		//LZ not implemented yet
		/*printf("Writing LZ file...\n");
		writeLz(argv[2]);
		printf("Compressing LZ file...\n");
		compressLz();*/
		printf("Done!\n");
	}
}
