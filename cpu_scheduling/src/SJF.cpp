#include "../include/SJF.h"
#include "../include/Process.h"
#include <string>

const int INT_MAX = 0xffff;

void SJF::running(Process* processes, int nums, bool preemptive)
{
	int index = 0;
	setNumsOfProcesses(nums);
	for (index = 0; index < nums; ++index)
	{
		setPid(index, processes[index].getPid());
		setName(index, processes[index].getName());
		setArrivalT(index, processes[index].getArrivalT());
		setRespondT(index, processes[index].getBurstT());
		setPriority(index, processes[index].getPriority());
	}
	if (preemptive)
	{
		findWaitingTime();
	} else 
	{
		findWaitingTimeNoP();
	}
	calculateTurnAround();	
}
void SJF::findWaitingTime()
{
	int index;
	int complete = 0;
	int current = 0;
	int minm = INT_MAX;
	int shortest = 0;
	int name_current = -1;
	int finish_time = 0;
	bool check = false;
	int rt[PID];
	for (index = 0; index < getNumsOfProcesses(); ++index)
	{
		rt[index] = getRespondT(index);
	}
	while (complete != getNumsOfProcesses())
	{
		for (index = 0; index < getNumsOfProcesses(); ++index)
		{
			if ((getArrivalT(index) <= current) && (rt[index] < minm) && rt[index] > 0)
			{
				minm = rt[index];
				shortest = index;
				check = true;
			}
		}
		if (shortest != name_current)
		{
			insertGanttChart(std::to_string(current));
			insertGanttChart(getName(shortest));
			name_current = shortest;
		}
		if (!check)
		{
			++current;
			continue;
		}
		--rt[shortest];
		minm = rt[shortest];
		if (minm == 0)
		{
			minm = INT_MAX;
		}
		if (rt[shortest] == 0)
		{
			++complete;
			check = false;
		
			finish_time = current + 1;
			setWaitingT(shortest, finish_time - getRespondT(shortest) - getArrivalT(shortest));
		
			if (getWaitingT(shortest) < 0)
			{
				setWaitingT(shortest, 0);
			
			}
		}
		++current;
	}
	insertGanttChart(std::to_string(current));
}

void SJF::findWaitingTimeNoP()
{
	int index = 0;
	int current = 0;
	int minm = INT_MAX;
	int value_waiting;
	int shortest = 0;
	int rt[PID];
	bool check = false;
	bool check_arri = false;
	int complete = 0;
	for (index = 0; index < getNumsOfProcesses(); ++index)
	{
		rt[index] = getRespondT(index);
		if (getArrivalT(index) == 0) 
		{
			check_arri = true;
		}
	}
	if (!check_arri)
	{
		insertGanttChart("0");
	}
	while (complete != getNumsOfProcesses())
	{
		for (index = 0; index < getNumsOfProcesses(); ++index)
		{
			if (getArrivalT(index) <= current && rt[index] < minm && rt[index] > 0)
			{
				shortest = index;
				minm = rt[shortest];
				check = true;
				
			}
		}
		if (!check)
		{
			++current;
			continue;
		}
		insertGanttChart(std::to_string(current));
		insertGanttChart(getName(shortest));
		setWaitingT(shortest, current - getArrivalT(shortest));
		current += rt[shortest];
		rt[shortest] = 0;
		minm = INT_MAX;
		check = false;	
		++complete;
	}
	insertGanttChart(std::to_string(current));
}

