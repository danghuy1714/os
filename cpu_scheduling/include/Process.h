#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <iostream>

class Process
{
private:
	int pid;
	std::string name;
	int burst_t;
	int arrival_t;
	int priority;
public:
	Process();
	~Process();
public:
	void setPid(int pid);
	int getPid();
	
	void setName(std::string name);
	std::string getName();
	
	void setBurstT(int burst_t);
	int getBurstT();
	
	void setArrivalT(int arrival_t);
	int getArrivalT();
	
	void setPriority(int priority);
	int getPriority();
};

#endif
