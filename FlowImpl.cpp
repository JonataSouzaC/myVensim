#include "FlowImpl.h"
#include<iostream>

FlowImpl::FlowImpl()
{
}

FlowImpl::FlowImpl(string name, Stock *source, Stock *destiny)
{
	this->name = name;
	this->source = source;
	this->destiny = destiny;


}

FlowImpl::FlowImpl(Flow &flow)
{
	name = flow.getName();
	source = flow.getSource();
	destiny = flow.getDestiny();


}
/*
FlowImpl& FlowImpl::operator=(Flow &flow) {
	if(this != &flow){
		this->name.clear();
		this->name = flow.getName();
		this->source = flow.getSource();
		this->destiny = flow.getDestiny();
	}
	return *this;
}

*/

string FlowImpl:: getName(){
	return this->name;
}


Stock * FlowImpl::getSource()
{
	return this->source;
}

Stock * FlowImpl::getDestiny()
{
	return this->destiny;
}

void  FlowImpl::setSource(Stock *source){
	this->source = source;
	
}

void  FlowImpl::setDestiny(Stock *destiny){
	this->destiny =  destiny;
	
}

void  FlowImpl::setName(string name){
	this->name = name;
	
}

FlowImpl::~FlowImpl()
{
	
}
