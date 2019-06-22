#pragma once
#include<String>
using namespace std;

class Stock
{
	
public:
	//virtual Stock &operator=(const Stock &)=0;
	virtual void setValue(float)=0;
	virtual void setName(string)=0;
	virtual float getValue()=0;
	virtual string getName()=0;
	
};

