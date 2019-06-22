#pragma once
#include<vector>
//#include"Flow.h" 
#include "Model.h"
#include "Body.h"

#include<String>
class ModelImpl: public Body
{
private: 
	vector<Flow*>flows;
	vector<Stock*>stocks;
	//vector<Model*> model;
	string name;
	
public:

   // ModelImpl &operator=(Model &model);
	ModelImpl(Model &model);	
    ModelImpl(string);
    ModelImpl();
	
	Stock* getStocks(int);
	Flow* getFlows(int);


	Model::itFlow flowBegin();
    Model::itFlow flowEnd();
    Model::itStock stockBegin();
    Model::itStock stockEnd();
    Model::itModel modelBegin();
    Model::itModel modelEnd();

	
	void setFlows(Flow*);
	void setStocks(Stock*);
	void setModels(Model* model);
    void setName(string);
	string getName();
	//vector<FlowImpl*> getFlows();
	//vector<StockImpl*> getStocks();
	~ModelImpl();
	void execute(int,int,int);	
	static Model* newModel();
    Stock& newStock(double,string);
//    Flow& newFlowExp();

	//    Flow& newFlowLog();
   // ModelImpl &operator=(Model &model);
};

