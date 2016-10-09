LZSCompress/DECompress   v0.9.6
by NFITC1
@ request of ff7rules via forums.qhimm.com

This program can compress or decompress files to/from LZS compression. Uses the "Haruhiko" method of compression used by Final Fantasy VII data files. As a result, it can be rather slow.

Usage:
Openning the executable will result in two text boxes and five buttons. The top text box is the source file to be compressed/decompressed and the second box is the destination file to be written. This is labled by the buttons next to each box. Pushing these buttons will bring up an Open File Dialogbox. From here you can navigate to the file you wish to use. If a source file is chosen then the second box will have the same path and file name with ".LZS" at the end of the filename.

Compress button:
This will begin compression. It can take a while even with moderately small files. A Progress Bar will display how close to completion creating the compressed file is. The compressed file will be written once compression is complete.

Decompress button:
If the source file is a lzs file the second box will still add .LZS to the end of the output file (TO BE FIXED). This program does not check to determine if the file is actually LZS compressed. It's possible that even a raw file could be "uncompressed", but I will not be held liable for the result.

Command line arguments:
This program can also be run via command line or a batch file. The batch file should have the extention "LBCH"
The command line, and each line of the batch file should have the following format:

For Compression:
	<sourcefile> C <destinationfile>
For Decompression:
	<sourcefile> D <destinationfile>

The filepaths should be absolute and may require quotes if spaces are in the paths.

Credits:
NFITC1 - Author
Ficedula - Documentation on LZS Compression Method.