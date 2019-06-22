#pragma once
#include<String>
#include"Stock.h"

using namespace std;

class Flow
{
public:
	
	//virtual Flow &operator=(Flow &)=0;
	virtual void setName(string)=0;
	virtual void setDestiny(Stock*)=0;
	virtual void setSource(Stock*)=0;
	virtual Stock* getSource()=0;
	virtual Stock* getDestiny()=0;
	virtual float executa()=0;
	virtual string getName()=0;
};

