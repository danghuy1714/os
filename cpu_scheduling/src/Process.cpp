#include <iostream>
#include "../include/Process.h"

Process::Process()
{
	priority = 0;
}
Process::~Process()
{

}

void Process::setPid(int pid)
{
	this->pid = pid;
}
int Process::getPid()
{
	return this->pid;
}

void Process::setName(std::string name)
{
	this->name = name;
}
std::string Process::getName()
{
	return this->name;
}

void Process::setBurstT(int burst_t)
{
	this->burst_t = burst_t;
}
int Process::getBurstT()
{
	return this->burst_t;
}

void Process::setArrivalT(int arrival_t)
{
	this->arrival_t = arrival_t;
}
int Process::getArrivalT()
{
	return this->arrival_t;
}

void Process::setPriority(int priority)
{
	this->priority = priority;
}
int Process::getPriority()
{
	return this->priority;
}
