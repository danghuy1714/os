#ifndef __SJF_H__
#define __SJF_H__

#include <iostream>
#include "Algorithm.h"
#include "Process.h"

class SJF : public Algorithm
{
private:
	unsigned int current_running_t;
	std::string name_sjf;
public:
	SJF () {}
	~SJF() {}
public:
	void running(Process* processes, int nums, bool preemptive);
	void findWaitingTime();
	void findWaitingTimeNoP();
};

#endif
