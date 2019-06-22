#pragma once
#ifndef SOCKHANDLE_H_
#define STOCKHANDLE_H_

#include "StockImpl.h"
#include "Handle.h"

class StockHandle: public Stock, public Handle<StockImpl> {
public:

	StockHandle() : Handle<StockImpl>() {
	
	}

	StockHandle( float value, string name) : Handle<StockImpl>() {
		pImpl_->setName(name);
		pImpl_->setValue(value);
	}


	virtual ~StockHandle() {

	}

	float getValue() {

		return pImpl_->getValue();
	}
	
	string getName() {
		return pImpl_->getName();
	}

	void setValue(float value) {
		pImpl_->setValue(value);
	}

	void setName(string name) {
		pImpl_->setName(name);
	}

};

#endif
