#pragma once
/**
 * \brief
 * 
 * The class Implementation was implemented based on the class teCounted writed by Ricardo Cartaxo 
 * and Gilberto Câmara and founded in the geographic library TerraLib.
 */
#include<iostream>
using namespace std;
class Body{	
public:
	/// Constructor: zero references when the object is being built
	Body(): refCount_ ( 0 ){  }
	

	/// Increases the number of references to this object
	void attach ()	{
			refCount_++; }

	/// Decreases the number of references to this object.
	/// Destroy it if there are no more references to it
	void detach (){	
		refCount_--;
		if ( refCount_ == 0 )	{ 

			delete this; 
			
		}

	}

	/// Returns the number of references to this object
	int refCount(){ return refCount_; }

	/// Destructor
	virtual ~Body(){}

private:

	/// No copy allowed
	Body(const Body&);

	/// Implementation
	Body& operator=(const Body&){return *this;}

	int refCount_; 	/// the number of references to this class

};


