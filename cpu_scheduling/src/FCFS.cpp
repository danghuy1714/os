#include <string>
#include "../include/FCFS.h"
#include "../include/Process.h"
#include "../include/Algorithm.h"

void FCFS::running(Process* processes, int nums)
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
	findWaitingTime();
	calculateTurnAround();
}
void FCFS::findWaitingTime()
{
	int index;
	int value_waiting = 0;
	int current = 0;
	if (getNumsOfProcesses())
	{
		setWaitingT(0, 0);
		if (getArrivalT(0) != 0)
		{
			insertGanttChart("0");
		}
		insertGanttChart(std::to_string(getArrivalT(0)));
		insertGanttChart(getName(0));
		// insertGanttChart(std::to_string(getArrivalT(0) + getRespondT(0)));
	}
	current = getArrivalT(0) + getRespondT(0);
	for (index = 1; index < getNumsOfProcesses(); ++index)
	{	
		value_waiting = current - getArrivalT(index);
		value_waiting = (value_waiting > 0) ? value_waiting : 0;
		insertGanttChart(std::to_string(current));
		if (current < getArrivalT(index))
		{
			current = getArrivalT(index);
			insertGanttChart(std::to_string(getArrivalT(index)));
		} 
		current += getRespondT(index);
		insertGanttChart(getName(index));
		setWaitingT(index, value_waiting);
	}
	insertGanttChart(std::to_string(current));
}
