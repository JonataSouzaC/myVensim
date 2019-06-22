#pragma once
#ifndef MODELHANDLE_H_
#define MODELHANDLE_H_

//#include"FlowImpl.h" 
#include "Handle.h"
#include "ModelImpl.h"
class ModelHandle: public Model, public Handle<ModelImpl> {
public:


    static vector<Model*> models;

	ModelHandle() : Handle<ModelImpl>() {
	
	}

/*	StockHandle( float value, string name) : Handle<StockImpl>() {
		pImpl_->setName(name);
		pImpl_->setValue(value);
	}
*/
/*
	virtual ~StockHandle() {

	}
*/
	  
	Stock* getStocks(int i){
		
		return pImpl_->getStocks(i);
		
	}
	
	Flow* getFlows(int i){

	return pImpl_->getFlows(i);

	}

    itModel modelBegin(){
		return pImpl_->modelBegin();
	}
    itModel modelEnd(){
		return pImpl_->modelEnd();
	}

	itFlow flowBegin(){
		
		return pImpl_->flowBegin();
	
	}
	
    itFlow flowEnd(){
		
		return pImpl_->flowEnd();

	}
	
    itStock stockBegin(){
		
		return pImpl_->stockBegin();
		
	}
    
	itStock stockEnd(){
		
		return pImpl_->stockEnd();
			
	}
		
	void setFlows(Flow*f) {
		
		pImpl_->setFlows(f);
		
	}
	
	void setStocks(Stock *s){
		
		pImpl_->setStocks(s);
	
	}
	
	void setModels(Model* model){
		  pImpl_->setModels(model);
	}
	  
    void setName(string name){
		
		pImpl_->setName(name);
		
	}
	
	string getName(){
		
		return pImpl_->getName();
		
	}
	//vector<FlowImpl*> getFlows();
	//vector<StockImpl*> getStocks();
	void execute(int a,int b,int c){
		
		return pImpl_->execute(a,b,c);
	
	}

		
	    //static Model* newModel();	
	static Model* newModel(){
		return newModel();
	}
	/*static Model& newModel(){
		
		return pImpl_->newModel();
	
	}*/
		
    Stock& newStock(double value,string name) {
		
		return pImpl_->newStock(value, name);
		
	
	}

};

#endif
