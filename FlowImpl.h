#pragma once
//#include"Stock.h"
#include<String>
#include "Body.h"
#include "Flow.h"

using namespace std;

class FlowImpl : public Body
{
private:
	string name;
	Stock *source, *destiny;
	
public:

	FlowImpl(string,Stock*,Stock*);
	FlowImpl(Flow &flow);
	FlowImpl();

	//FlowImpl &operator=(Flow &flow);
//	virtual float executa() = 0;
	string getName();
	void setSource(Stock *);
	void setDestiny(Stock*);
	void setName(string );
	Stock* getSource();
	Stock* getDestiny();
	~FlowImpl();
};

