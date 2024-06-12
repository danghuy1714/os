#include <iostream>
#include "../include/Algorithm.h"
#include "../include/RR.h"
#include <stack>
#include <string>
#include "../include/Process.h"


#define PID	100

RR::RR()
{
	RR::quantum = 4;
}
RR::~RR()
{

}

void RR::running(Process* processes, int nums)
{
	Algorithm::setNumsOfProcesses(nums);
	for (int i = 0; i < nums; ++i)
	{
		setPid(i, processes[i].getPid());
		setName(i, processes[i].getName());
		setArrivalT(i, processes[i].getArrivalT());
		setRespondT(i, processes[i].getBurstT());
		setPriority(i, processes[i].getPriority());
	}
	RR::findWaitingT();
	Algorithm::calculateTurnAround();
}

void RR::findWaitingT()
{
	int current = 0;
	int complete = 0;
	int nums = Algorithm::getNumsOfProcesses();
	int burst[PID];
	int waiting[PID];
	int first;
	bool c = false;
	for (int i = 0; i < nums; ++i)
	{
		burst[i] = Algorithm::getRespondT(i);
	}
	for (int i = 0; i < nums; ++i)
	{
		waiting[i] = -1;
	}
	while (complete != nums)
	{
		for (int i = 0; i < nums; ++i)
		{
			if (current >= Algorithm::getArrivalT(i) && waiting[i] == -1)
			{
				waiting[i] = 0;
				que.push(i);
			}
		}
		if (c) { que.push(first); }
		if (que.empty()) { ++current; continue; }
		first = que.front();
		burst[first] -= quantum;
		que.pop();
		int i_last = -1;
		std::string last = Algorithm::getLast();
		try {
			i_last = std::stoi(last);
		} catch (const std::invalid_argument& e)
		{
			int i = 0;
		}
		if (current != i_last) 
		{
				Algorithm::insertGanttChart(std::to_string(current));
		}
		Algorithm::insertGanttChart(Algorithm::getName(first));
		if (burst[first] <= 0) 
		{
			Algorithm::setWaitingT(first, waiting[first]);
			++complete;
			c = false;
		} else
		{
			c = true;
		}
		for (int i = 0; i < nums; ++i)
		{
			if (waiting[i] != -1 && i != first)
			{
				++waiting[i];
			}
		}
		if (burst[first] < 0) { current += burst[first]; }
		current += quantum;
		Algorithm::insertGanttChart(std::to_string(current));
	}
}
