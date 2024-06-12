#include <iostream>
#include "../include/Process.h"
#include "../include/Algorithm.h"
#include "../include/FCFS.h"
#include "../include/SJF.h"
#include "../include/Priority.h"
#include "../include/RR.h"

void ex_fcfs()
{
	const int nums = 5;
	Process process[nums];
	RR fcfs;
	process[0].setPid(1);
	process[0].setArrivalT(0);
	process[0].setBurstT(11);
	process[0].setPriority(2);
	process[0].setName("p0");
	
	process[1].setPid(2);
	process[1].setArrivalT(3);
	process[1].setBurstT(7);
	process[1].setPriority(3);
	process[1].setName("p1");
	
	process[2].setPid(3);
	process[2].setArrivalT(6);
	process[2].setBurstT(24);
	process[2].setPriority(4);
	process[2].setName("p2");
	
	process[3].setPid(4);
	process[3].setArrivalT(10);
	process[3].setBurstT(4);
	process[3].setPriority(5);
	process[3].setName("p3");
	
	process[4].setPid(5);
	process[4].setArrivalT(14);
	process[4].setBurstT(10);
	process[4].setPriority(5);
	process[4].setName("p4");
	
	// fcfs.running(process, nums, false);
	fcfs.running(process, nums);
	fcfs.printResult();
}

int main()
{	
	ex_fcfs();
	
	return 0;
}
