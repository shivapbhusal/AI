/*
Class created for Backpropagation  
CS 6200
Shiva Bhusal, Bowling Green State University

*/

struct HiddenNode 
{
	double w1; 
	double w2; 
	double w3; 
	double output; 

    HiddenNode (double a, double b, double c)
	{
		w1=a; 
		w2=b; 
		w3=c; 
		output=a*b*c; 
	}
}; 

#ifndef BACKPROP_H 
#define BACKPROP_H 

class BackProp{
	private:

	public: 
		HiddenNode *H=new HiddenNode(10,10,10); 
}; 

#endif 