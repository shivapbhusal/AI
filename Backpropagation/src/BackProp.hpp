/*
Class created for Backpropagation  
CS 6200
Shiva Bhusal, Bowling Green State University

*/

#include <math.h>  

class HiddenNode 
{

public:
	double w1=0; 
	double w2=0; 
	double w3=0; 
	double bias=0; 
	double output=0; 

    HiddenNode (double a, double b, double c, double d)
	{
		w1=a; 
		w2=b; 
		w3=c; 
		bias=d;  
	}

	void calculateOutput(double x, double y, double z)
	{
		double total=w1*x+w2*y+w3*z+bias; 
		output=(1/(1+pow(2.7,total)));  
	}
}; 

#ifndef BACKPROP_H 
#define BACKPROP_H 

class BackProp{
	private:

	public: 
		HiddenNode *H=new HiddenNode(0.1,0.1,0.1,0.1); 
}; 

#endif 