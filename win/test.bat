cd sample
../main.exe st099.obj config.txt
cd ..
cd sample/temp
../../lzdec/LZSCDec.exe output.lz.raw C output.lz.raw.lzs
../../lzdec/lzfix.exe
