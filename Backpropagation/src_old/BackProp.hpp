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
	double const THETA=0.5; 
	double w1=0.1; 
	double w2=0.1; 
	double w3=0.1; 
	double bias=0.5; 
	double total=0; 
	double output=0;

	void updateWeight(double adjustment, double indicator)
	{
		if (indicator==1){
		w1=w1-THETA*adjustment; 	
		}
		else if (indicator==2){
			w2=w2-THETA*adjustment; 
		}
		else if (indicator==3){
			w3=w3-THETA*adjustment; 
		}
		else {
			std::cout<<"Invalid value of indicator"; 
		}
	}

	double getOutput(double x, double y, double z)
	{
		total=w1*x+w2*y+w3*z+bias; 
		output=1/(1+pow(2.7,total));

		//std::cout<<output; 
		return output;   
	}
}; 

class BackProp{

	public: 

		// To find the output for test dataset after the training process.
		double finalOutput=0; 

		double errorTotal=1;
		// Create three hidden nodes. 
		Node *H1=new Node(); 
		Node *H2=new Node(); 
		Node *H3=new Node(); 

		//Create three output Nodes. 
	    Node *out=new Node();

	void trainModel(double trainingData[4][45])
	{
		int count=0; 
		while (count<1000)
		{
			count=count+1;  

		for (int i=0;i<45;i++)
			{
			double outNetH1=H1->getOutput(trainingData[0][i],trainingData[1][i],trainingData[2][i]); 
			double outNetH2=H2->getOutput(trainingData[0][i],trainingData[1][i],trainingData[2][i]); 
			double outNetH3=H3->getOutput(trainingData[0][i],trainingData[1][i],trainingData[2][i]); 

			double result=out->getOutput(outNetH1,outNetH2,outNetH3);
			double expected=trainingData[3][i]; 

			double error=sqrt(result-expected); 

			double adjustment=-error*(out->output)*(1-(out->output))*H1->output;  
			out->updateWeight(adjustment,1); 
			out->updateWeight(adjustment,2);
			out->updateWeight(adjustment,3); 

			// Weight adjustment -- Two

			adjustment=(H1->w1)*-(expected-result)*(H1->output)*(1-(H1->output));  
			H1->updateWeight(adjustment,1); 
			H1->updateWeight(adjustment,2);
			H1->updateWeight(adjustment,3); 

			adjustment=(H2->w1)*-(expected-result)*(H2->output)*(1-(H2->output));  
			H2->updateWeight(adjustment,1); 
			H2->updateWeight(adjustment,2);
			H2->updateWeight(adjustment,3); 

			adjustment=(H2->w1)*-(expected-result)*(H3->output)*(1-(H3->output));  
			H3->updateWeight(adjustment,1); 
			H3->updateWeight(adjustment,2);
			H3->updateWeight(adjustment,3); 

		}


			}
		
					std::cout<<errorTotal<<" "<<count<<std::endl; 
	}

   void calculateFinal(double x, double y, double z)
   {
   	    double total1=H1->w1*x+H1->w2*y+H1->w3*z+H1->bias; 
		double output1=1/(1+pow(2.7,total1));

   	    double total2=H2->w1*x+H2->w2*y+H2->w3*z+H1->bias; 
		double output2=1/(1+pow(2.7,total2));

		double total3=H2->w1*x+H2->w2*y+H2->w3*z+H1->bias; 
		double output3=1/(1+pow(2.7,total3));

		double total4=out->w1*output1+out->w2*output2+out->w3*output3+out->bias;
		finalOutput=1/(1+pow(2.7,-total4));

		std::cout<<finalOutput<<std::endl; 
   }
}; 

#endif 