#ifndef __FCFS_H__
#define __FCFS_H__

#include "Algorithm.h"
#include "Process.h"

class FCFS : public Algorithm
{
public:
	FCFS() {}
	~FCFS() {}
public:
	void running(Process* processes, int nums);
	void findWaitingTime();
};

#endif
