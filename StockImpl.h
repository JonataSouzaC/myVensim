//#pragma once
#include<String>
//#include "Stock.h"
#include "Body.h"
using namespace std;

class StockImpl : public Body
{
private:
	float value;
	string name;
public:

//	StockImpl &operator=(const Stock &stock);
	StockImpl();
	StockImpl(float value, string name);
	//StockImpl(Stock &stock);	
	~StockImpl();
	void setValue(float value);
	void setName(string name);
	float getValue();
	string getName();
	
};

