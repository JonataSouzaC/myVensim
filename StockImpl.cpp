
#include "StockImpl.h"

#include <iostream>
using namespace std;

StockImpl::StockImpl() {
	

}
StockImpl::StockImpl(float value, string name) {

	this->value = value;
	this->name = name;

}
/*
StockImpl::StockImpl(Stock &stock){
	name = (*new string(stock.getName()));
	value =(* new float( stock.getValue()));
	
}
*/
StockImpl::~StockImpl()

{


}

void StockImpl::setValue(float value)
{
	this->value = value;

}


void StockImpl::setName(string name) {

	this->name = name;

}


float StockImpl::getValue() {

	return this->value;

}

string StockImpl::getName() {

	return this->name;

}
/*
StockImpl& StockImpl::operator=(const Stock &stock) {
	if(this == &stock){

		return *this;
	}

   	this->name = stock.getName();
	this->value = stock.getValue();

	//cout<<"TA AQUI22";
	return *this;
}

*/