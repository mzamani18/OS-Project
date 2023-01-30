all: main.cpp Process.h FIFO.h FCFS.h SJF.h
	g++ Process.h -o Process
	g++ FIFO.h -o FIFO
	g++ FCFS.h -o FCFS
	g++ SJF.h -o SJF
	g++ -std=c++14 -o main main.cpp -lpthread -I.