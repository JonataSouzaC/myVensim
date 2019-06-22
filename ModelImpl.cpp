//#pragma once
#include "ModelImpl.h"
#include "FlowUser.cpp"
#include "StockHandle.h"
#include "ModelHandle.h"
#include "FlowHandle.h"
#include <vector>
#include <iostream>
using namespace std;


vector<Model*> ModelHandle::models;


void ModelImpl::setModels(Model* model){

   ModelHandle::models.push_back(model);

}


ModelImpl::ModelImpl(string name)
{
	this->name = name;
}

ModelImpl::ModelImpl()
{

}

ModelImpl::ModelImpl(Model &model)
{
	if((Model*)this != &model){

		flows.clear();
		stocks.clear();
		this->name = model.getName();
		Model::itFlow itf;
        for (itf =  model.flowBegin() ;itf != model.flowEnd(); ++itf)
            this->setFlows(*itf);

        Model::itStock its = model.stockBegin();
        for (; its != model.stockEnd(); ++its)
            this->setStocks(*its);       		
	}
}


/*
ModelImpl& ModelImpl::operator=(Model &model) {
	//flow f = new FlowExponencial();
	if(this != &model){

		this->name = model.getName();
		flows.clear();
		stocks.clear();
		
		itFlow itf=  model.flowBegin();
        for (;itf != model.flowEnd(); ++itf){ //NAO SEI FAZER ISSO, HELP
			Flow *f;
			f = dynamic_cast<FlowImpl*>(*itf);
					
			this->setFlows(f);	
		
		}
        itStock its = model.stockBegin();
        for (; its != model.stockEnd(); ++its){ //Pro stock funciona 
			Stock *aux = new StockImpl();
			*aux = **its;
		    this->setStocks(aux);       		
		}	
	}

	return *this;
}


*/
ModelImpl::~ModelImpl()
{
	Model::itStock itS;
	for(itS = this->stocks.begin(); itS!=this->stocks.end(); itS++){
        delete (StockHandle*)*itS;
    }

    stocks.clear();
	
	Model::itFlow itF;
    for(itF = this->flows.begin(); itF!=this->flows.end(); itF++){
	   delete *itF;
    }

    flows.clear();

	Model::itModel itM;
    for(itM = ModelHandle::models.begin(); itM != ModelHandle::models.end(); itM++){

        delete (ModelHandle*)*itM;
    }

    ModelHandle::models.clear();

	
}

void ModelImpl::setStocks(Stock*s ){
	
	this->stocks.push_back(s);
	
}
/*
int ModelImpl::getSizeF( ){
	return flows.size();
}


int ModelImpl::getSizeS( ){
	return stocks.size();
}
*/
void ModelImpl::setFlows(Flow*f ){

	//cout<<"tamanho de flows:"<<flows.size();
	this->flows.push_back(f);
	
}

Flow* ModelImpl::getFlows(int i){
	return this->flows[i];	

}

Stock* ModelImpl::getStocks(int i){
	return this->stocks[i];	
}


void ModelImpl::setName(string name ){
	
	this->name = name;
	
}

string ModelImpl::getName(){
	
	return this->name;
	
}
/*
 FlowImpl* ::ModelImpl getFlows(){
	 
	 return this->flows.pop_back();
	
}


 StockImpl*::ModelImpl getStocks(){
	 
	 return this->stocks.pop_back();
	
}
*/
void ModelImpl::execute(int iniTime, int finTime, int passes) 
{
	Stock *source,*destiny;
	Flow *aux;
	float v[50];
	for (int i = iniTime; i < finTime; i++) {

		for (int j = 0; j < flows.size(); j++) { //até o tamanho do vetor de fluxos
			
			aux = this->flows[j];
			v[j] = aux->executa();
		//	cout<<v[j]<<endl;
		}

		for (int j = 0; j < flows.size(); j++) { //até o tamanho do vetor de fluxos
		
			source = this->flows[j]->getSource();
			destiny = this->flows[j]->getDestiny();
			source->setValue(source->getValue() - v[j]);
			destiny->setValue(destiny->getValue() + v[j]);
	
		}

	}

}



Model::itFlow ModelImpl::flowBegin(){
    return flows.begin();
}

Model::itFlow ModelImpl::flowEnd(){
    return flows.end();
}

Model::itStock ModelImpl::stockBegin(){
    return stocks.begin();
}

Model::itStock ModelImpl::stockEnd(){
    return stocks.end();
}

Model::itModel ModelImpl::modelBegin(){
    return ModelHandle::models.begin();
}

Model::itModel ModelImpl::modelEnd(){
    return ModelHandle::models.end();
}


Model* Model::newModel(){

    return ModelImpl::newModel();

}
Model* ModelImpl::newModel(){

    ModelHandle* p = new ModelHandle();

    ModelHandle::models.push_back(p);

    return p;

}


/*
Model& ModelImpl::newModel(){

    Model *model = new ModelHandle();
    this->model.push_back(model);

    return *model;

}
*/
Stock& ModelImpl::newStock(double value, string name){

    Stock *stock = new StockHandle(value,name);
    this->stocks.push_back(stock);

    return *stock;

}

