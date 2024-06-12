#include <iostream>
#include <vector>
#include <iomanip>
#include "../include/Algorithm.h"

#define SIZEAVG 	5
#define SIZEPID		7
#define SIZEARRIVAL 	16
#define SIZEBURST 	16
#define SIZEPRIORITY  	12	
#define SIZETAROUND	20
#define SIZEWAITING	20
#define COUNT_ATTRI	7

void Algorithm::setPid(int index, int value)
{
	this->pid[index] = value;
}
void Algorithm::setName(int index, std::string value)
{
	this->name[index] = value;
}
std::string Algorithm::getName(int index)
{
	return this->name[index];
}
void Algorithm::setArrivalT(int index, int value)
{
	this->arrival_t[index] = value;
}
int Algorithm::getArrivalT(int index)
{
	return arrival_t[index];
}
void Algorithm::setRespondT(int index, int value)
{
	this->respond_t[index] = value;
}
int Algorithm::getRespondT(int index)
{
	return respond_t[index];
}
void Algorithm::setPriority(int index, int value)
{
	this->priority[index] = value;
}
void Algorithm::setNumsOfProcesses(unsigned int nums_of_processes)
{
	this->nums_of_processes = nums_of_processes;
}
int Algorithm::getPriority(int index)
{
	return priority[index];
}
int Algorithm::getNumsOfProcesses()
{
	return this->nums_of_processes;
}
void Algorithm::setWaitingT(int index, int value)
{
	waiting_t[index] = value;
}
int Algorithm::getWaitingT(int index)
{
	return waiting_t[index];
}
void Algorithm::insertGanttChart(std::string ele)
{
	gantt_chart.push_back(ele);
}
std::string Algorithm::getLast()
{
	if (gantt_chart.size() == 0) { return ""; }
	return gantt_chart.back();
}
void Algorithm::calculateTurnAround()
{
	int index;
	for (index = 0; index < nums_of_processes; ++index)
	{
		turn_around_t[index] = waiting_t[index] + respond_t[index];
	}
}
double avg(int* array, int nums)
{
	int total = 0;
	int index;
	double avg = 0;
	for (index = 0; index < nums; ++index)
	{
		total += array[index];
	}
	avg = 1.0 * total / nums;
	return avg;
}
double Algorithm::avgWaiting()
{
	double avg_waiting_time = avg(waiting_t, nums_of_processes);
	return avg_waiting_time;
}
double Algorithm::avgRespond()
{
	double avg_respond_time = avg(respond_t, nums_of_processes);
	return avg_respond_time;
}
double Algorithm::avgTurnAround()
{
	double avg_turn_around = avg(turn_around_t, nums_of_processes);
	return avg_turn_around;
}

void Algorithm::printResult()
{
	int index;
	std::vector<std::string>::iterator ite;
	
	std::cout << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(SIZEAVG) << " ";
	std::cout << '|';
	std::cout << std::setw(SIZEPID) << "PID";
	std::cout << '|';
	std::cout << std::setw(SIZEARRIVAL) << "Arrival Time";
	std::cout << '|';
	std::cout << std::setw(SIZEBURST) << "Burst Time";
	std::cout << '|';
	std::cout << std::setw(SIZEWAITING)  << "Waiting Time";
	std::cout << '|';
	std::cout << std::setw(SIZETAROUND) << "Turn around time";
	std::cout << '|';
	std::cout << std::setw(SIZEPRIORITY) << "Priority";
	std::cout << '|';
	for (index = 0; index < nums_of_processes; ++index)
	{
		std::cout << std::endl;
		std::cout << std::setw(SIZEAVG) << " ";
		std::cout << '|';
		std::cout << std::setw(SIZEPID) << this->pid[index];
		std::cout << '|';
		std::cout << std::setw(SIZEARRIVAL) << this->arrival_t[index];
		std::cout << '|';
		std::cout << std::setw(SIZEBURST) << this->respond_t[index];
		std::cout << '|';
		std::cout << std::setw(SIZEWAITING)  << this->waiting_t[index];
		std::cout << '|';
		std::cout << std::setw(SIZETAROUND) << this->turn_around_t[index];
		std::cout << '|';
		std::cout << std::setw(SIZEPRIORITY) << this->priority[index];
		std::cout << '|';
		
	}
	std::cout << std::endl;
	std::cout << std::setfill('-') << std::setw(SIZEAVG+SIZEPID+SIZEARRIVAL+SIZEBURST+SIZEPRIORITY+SIZEWAITING+SIZETAROUND+COUNT_ATTRI) << "-";
	std::cout << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(SIZEAVG) << "AVG";
	std::cout << '|';
	std::cout << std::setw(SIZEPID) << " ";
	std::cout << '|';
	std::cout << std::setw(SIZEARRIVAL) << " ";
	std::cout << '|';
	std::cout << std::setw(SIZEBURST) << avgRespond();
	std::cout << '|';
	std::cout << std::setw(SIZEWAITING)  << avgWaiting();
	std::cout << '|';
	std::cout << std::setw(SIZETAROUND) << avgTurnAround();
	std::cout << '|';
	std::cout << std::setw(SIZEPRIORITY) << " ";
	std::cout << '|';
	std::cout << std::endl;
	ite = gantt_chart.begin();
	while (ite != gantt_chart.end())
	{
		std::cout << *ite;
		if (ite != gantt_chart.end())
		{
			std::cout << " -> ";
		} 
		++ite;
	}
	std::cout << std::endl;
}
