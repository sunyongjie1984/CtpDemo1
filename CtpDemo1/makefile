#cflag = -g -Wall -std==c++11 -D _linux
cflag = -g -Wall -D _linux
INCLUDE = -I tools -I .
all: CtpDemo1
CtpDemo1: frame_app.o CtpDemo1.o MyTraderSpi.o main.o event.o util.o log_impl.o config_impl.o options_impl.o thread_mutex.o
	g++ -o CtpDemo1 ${cflag} frame_app.o CtpDemo1.o main.o MyTraderSpi.o event.o log_impl.o util.o config_impl.o options_impl.o thread_mutex.o -lthosttraderapi -lpthread -L .
main.o: main.cpp tools/event.h
	g++ -c ${cflag} main.cpp ${INCLUDE}
event.o: tools/event.cpp
	g++ -c ${cflag} tools/event.cpp ${INCLUDE}
util.o: tools/util.cpp
	g++ -c ${cflag} tools/util.cpp ${INCLUDE}
MyTraderSpi.o: MyTraderSpi.cpp tools/event.h
	g++ -c ${cflag} MyTraderSpi.cpp ${INCLUDE}
log_impl.o: tools/log_impl.cpp
	g++ -c ${cflag} tools/log_impl.cpp ${INCLUDE}
config_impl.o: tools/config_impl.cpp
	g++ -c ${cflag} tools/config_impl.cpp ${INCLUDE}
options_impl.o: tools/options_impl.cpp
	g++ -c ${cflag} tools/options_impl.cpp ${INCLUDE}
thread_mutex.o: tools/thread_mutex.cpp
	g++ -c ${cflag} tools/thread_mutex.cpp ${INCLUDE}
CtpDemo1.o: CtpDemo1.cpp
	g++ -c ${cflag} CtpDemo1.cpp ${INCLUDE}
frame_app.o: tools/frame_app.cpp
	g++ -c ${cflag} tools/frame_app.cpp ${INCLUDE}
clean :
	rm -rf *.o CtpDemo1 *.dSYM *.log *.con core*
allclean :
	rm -rf *.o CtpDemo1 *.dSYM *.log *.con core* log/*
