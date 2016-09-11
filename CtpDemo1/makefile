#cflag = -g -Wall -std==c++11 -D _linux
cflag = -g -Wall -D _linux
INCLUDE = -I tools -I .
all: CtpDemo1
CtpDemo1: MyTraderSpi.o main.o event.o util.o
	g++ -o CtpDemo1 ${cflag} main.o MyTraderSpi.o event.o util.o -lthosttraderapi -L .
main.o: main.cpp tools/event.h
	g++ -c ${cflag} main.cpp ${INCLUDE}
event.o: tools/event.cpp
	g++ -c ${cflag} tools/event.cpp ${INCLUDE}
util.o: tools/util.cpp
	g++ -c ${cflag} tools/util.cpp ${INCLUDE}
MyTraderSpi.o: MyTraderSpi.cpp tools/event.h
	g++ -c ${cflag} MyTraderSpi.cpp ${INCLUDE}
clean :
	rm -rf *.o CtpDemo1 *.dSYM *.log *.con core*
