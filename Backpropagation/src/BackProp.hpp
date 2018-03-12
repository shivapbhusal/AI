/*
Class created for Backpropagation  
CS 6200
Shiva Bhusal, Bowling Green State University

*/
#ifndef BACKPROP_H 
#define BACKPROP_H 

#include <math.h>  

class Node 
{

public:
	double w1=0; 
	double w2=0; 
	double w3=0; 
	double bias=0.2; 

    Node (double a, double b, double c, double d)
	{
		w1=a; 
		w2=b; 
		w3=c; 
		bias=d;  
	}

	void updateWeight(double newW1, double newW2, double newW3)
	{
		w1=newW1; 
		w2=newW2; 
		w3=newW3; 
	}

	double getOutput(double x, double y, double z)
	{
		double total=w1*x+w2*y+w3*z+bias; 
		double output=(1/(1+pow(2.7,total)));
		return output;   
	}
}; 

class BackProp{

	public: 
		// Create three hidden nodes. 
		Node *H1=new Node(0.1,0.1,0.1,0.1); 
		Node *H2=new Node(0.1,0.1,0.1,0.1); 
		Node *H3=new Node(0.1,0.1,0.1,0.1); 

		//Create three output Nodes. 
	    Node *out1=new Node(0.5,0.6,0.7,0.1); 
	    Node *out2=new Node(0.5,0.6,0.7,0.1); 
	    Node *out3=new Node(0.5,0.6,0.7,0.1); 


	void trainModel(double x, double y, double z, double expected)
	{
		double outNetH1=H1->getOutput(x,y,z); 
		double outNetH2=H2->getOutput(x,y,z); 
		double outNetH3=H3->getOutput(x,y,z); 

		double resultA=out1->getOutput(outNetH1,outNetH2,outNetH3);
		double resultB=out2->getOutput(outNetH1,outNetH2,outNetH3); 
		double resultC=out3->getOutput(outNetH1,outNetH2,outNetH3);

	}
}; 

#endif 