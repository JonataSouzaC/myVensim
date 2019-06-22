#pragma once
#include <vector>
#include<String>
#include "Flow.h"
//#include "FlowUser.h"
#include "FlowHandle.h" //isso ta fodendo
//#include "Stock.h"

class Model
{
	
public:
	
	virtual void execute(int,int,int)=0;
    virtual Stock* getStocks(int)=0;
    virtual Flow* getFlows(int)=0;
	virtual string getName()=0;
	virtual void setName(string)=0;
	virtual void setStocks(Stock*)=0;
	virtual void setFlows(Flow*)=0;
	//virtual Model &operator=(Model &)=0;
	//virtual FlowImpl* getFlow()=0;
	//virtual FlowImpl* getStock()=0;
  
    static Model* newModel();	
    //virtual Model& newModel()=0;
    virtual Stock& newStock(double,string)=0;
  
	template<typename FLOW_TYPE>
	Flow& createFlow(){
		Flow *f = new FlowHandle<FLOW_TYPE>;

		this->setFlows(f);

		return *f;
	}
	
	typedef vector<Flow*>::iterator itFlow;
	virtual itFlow flowBegin() = 0;
    virtual itFlow flowEnd() = 0;

    typedef vector<Stock*>::iterator itStock;
	virtual itStock stockBegin() = 0;
    virtual itStock stockEnd() = 0;

	typedef vector<Model*>::iterator itModel;
	virtual itModel modelBegin() = 0;
    virtual itModel modelEnd() = 0;

  };

