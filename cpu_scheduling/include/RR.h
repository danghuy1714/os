#ifndef __RR_H__
#define __RR_H__

#include "Process.h"
#include "Algorithm.h"
#include <queue>

class RR : public Algorithm
{
private:
	int quantum;
	std::queue<int> que;
public:
	RR();
	~RR();
public:
	void running(Process* processes, int nums);
	void findWaitingT();
};

#endif
