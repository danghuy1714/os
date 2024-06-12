#include <iostream>
#include <string>
#include "../include/Priority.h"
#include "../include/Process.h"
#include "../include/Algorithm.h"

#define MAX 0xff
#define PID 100

Priority::Priority() 
{

}

Priority::~Priority()
{

}

void Priority::running(Process* processes, int nums)
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
	Priority::findWaitingT();
	Priority::calculateTurnAround();
}

void Priority::findWaitingT()
{
	int current = 0;
	int complete = 0;
	int now = -1;
	int run = 0xff;
	int nums = Algorithm::getNumsOfProcesses();
	int arrival[PID];
	for (int i = 0; i < nums; ++i)
	{
		arrival[i] = Algorithm::getArrivalT(i);
	}
	Algorithm::insertGanttChart("0");
	while (complete != nums)
	{
		run = 0xff;
		for (int i = 0; i < nums; ++i)
		{
			if (current >= arrival[i])
			{
				int priority = Algorithm::getPriority(i);
				if (priority < run)
				{
					run = priority;
					now = i;
				}
			}
		}
		if (now == -1 || run == 0xff) { ++current; continue; }
		Algorithm::setWaitingT(now, current - arrival[now]);
		++complete;
		current += Algorithm::getRespondT(now);
		std::string last = Algorithm::getLast();
		int i_last = -1;
		try {
			i_last = std::stoi(last);
		} catch (const std::invalid_argument& e)
		{
			int i = 0;
		}
		if (i_last != -1 && arrival[now] > current)
		{
			Algorithm::insertGanttChart(std::to_string(arrival[now]));
		}
		Algorithm::insertGanttChart(Algorithm::getName(now));
		Algorithm::insertGanttChart(std::to_string(current));
		arrival[now] = 0xff;
	}
}
