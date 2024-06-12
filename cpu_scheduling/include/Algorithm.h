#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <iostream>
#include <vector>

#define PID			100
#define	ARRIVAL			100
#define WAITING			100
#define	RESPOND			100
#define PRIORITY		100
#define	TAROUND			100
#define	REMAININGBURST		100

class Algorithm
{
private:
	int pid[PID];
	std::string name[PID];
	int arrival_t[PID];
	int waiting_t[WAITING];
	int respond_t[PID];
	int priority[PID];
	int turn_around_t[WAITING];
	std::vector<std::string> gantt_chart;
	int nums_of_processes;
public:
	Algorithm() {}
	~Algorithm() {}
	
public:
	void setPid(int, int);
	
	void setName(int, std::string);
	std::string getName(int);
	
	void setArrivalT(int, int);
	int getArrivalT(int);
	
	void setRespondT(int, int);
	int getRespondT(int);
	
	void setPriority(int, int);
	int getPriority(int);
	
	void setWaitingT(int, int);
	int getWaitingT(int);
	
	void insertGanttChart(std::string);
	std::string getLast();

	void setNumsOfProcesses(unsigned int);
	int getNumsOfProcesses();
	
public:
	void calculateTurnAround();
	double avgWaiting();
	double avgRespond();
	double avgTurnAround();
public:
	void printResult();
};

#endif
