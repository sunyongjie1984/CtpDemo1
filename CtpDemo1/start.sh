make clean
make
. ./env
./CtpDemo1 -f CtpDemo1.ini 2>&1 | tee a.log
