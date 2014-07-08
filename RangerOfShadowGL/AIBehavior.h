#pragma once
#include "headers.h"
class CAIBehavior
{
public:
	CAIBehavior(void){};
	virtual int useMind() = 0;
	virtual int useMind(int*,int,int,int) = 0;
	virtual int setPos() = 0;
	~CAIBehavior(void){};
};

class CSimpleAI: public CAIBehavior
{
public:
	CSimpleAI(){}
	int useMind(){return 0;}
	int useMind(int*,int,int,int);
	int setPos(){return 0;};
	~CSimpleAI(){}
};