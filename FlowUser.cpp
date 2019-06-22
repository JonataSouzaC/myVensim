#include "FlowImpl.h"

class FlowExponencial :public FlowImpl
{
	
	public:
	FlowExponencial(){
	//		super(string,Stock*,Stock*);
		};
		~FlowExponencial(){};
		
	
		
		float executa()
		{ 
			return (0.01*getSource()->getValue());
		};
};


class FlowLogistica :public FlowImpl
{
	
	public:
		FlowLogistica(){
		};
		
	~FlowLogistica(){};
		
	
		
	float executa()
		{ 
			return 0.01*getDestiny()->getValue()*(1 - getDestiny()->getValue() / 70);
		};
};

