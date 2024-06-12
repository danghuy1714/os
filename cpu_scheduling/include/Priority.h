#ifndef __PRIORITY_H__
#define __PRIORITY_H__

#include <iostream>
#include "Process.h"
#include "Algorithm.h"

class Priority : public Algorithm 
{
public:
	Priority();
	~Priority();
public:
	void running(Process*, int);
	void findWaitingT();
};

#endif
