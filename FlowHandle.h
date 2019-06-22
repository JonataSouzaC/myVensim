#pragma once
#ifndef FLOWANDLE_H_
#define FLOWHANDLE_H_

//#include "FlowImpl.h"
#include "Handle.h"


template<class T>
class FlowHandle: public Flow, public Handle<T> {
public:

	FlowHandle() : Handle<T>() {
	
	}

	FlowHandle( string name,Stock *source,Stock *destiny) : Handle<T>() {
		this->pImpl_->setName(name);
		this->pImpl_->setSource(source);
		this->pImpl_->setDestiny(destiny);
	}


	virtual ~FlowHandle() {

	}


	Stock* getDestiny() {
		return this->pImpl_->getDestiny();
	}


	void setDestiny(Stock* destiny) {
		this->pImpl_->setDestiny(destiny);
	}


	string getName() {
		return this->pImpl_->getName();
	}


	void setName(string nome) {
		this->pImpl_->setName(nome);
	}


	Stock* getSource() {
		return this->pImpl_->getSource();
	}


	void setSource(Stock* source) {
		this->pImpl_->setSource(source);
	}


	virtual float executa() {
		return this->pImpl_->executa();
	}

};

#endif
