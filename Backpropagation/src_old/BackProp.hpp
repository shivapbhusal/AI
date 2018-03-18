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
	double w2=0.5; 
	double w3=0.3; 
	double bias=0.5; 
	double total=0; 
	double output=0;

	void updateWeight(double adjustment1, double adjustment2, double adjustment3)
	{
		w1=w1-adjustment1; 
		w2=w2-adjustment2; 
		w3=w3-adjustment3; 
	}

	void getOutput(double x, double y, double z)
	{
		total=w1*x+w2*y+w3*z+bias; 
		output=1/(1+exp((-1)*total));

		//std::cout<<output; 
		//return output;   
	}
}; 

class BackProp{

	public: 

		// To find the output for test dataset after the training process.
		double finalOutput=0; 

		double errorTotal=1;
		// Create three hidden nodes. 
		Node H1; 
		Node H2;  
		Node H3; 

		//Create three output Nodes. 
	    Node out; 

	void trainModel(double trainingData[4][45])
	{
		double error=0; 
		int count=0; 
		double totalError=0.9; 
		while (totalError>0.50)
		{		
			totalError=0; 
			for (int i=0;i<45;i++)
			{
				count=count+1; 

				H1.getOutput(trainingData[0][i],trainingData[1][i],trainingData[2][i]);
				H2.getOutput(trainingData[0][i],trainingData[1][i],trainingData[2][i]);  
				H3.getOutput(trainingData[0][i],trainingData[1][i],trainingData[2][i]); 

			double outNetH1=H1.output; 
			double outNetH2=H2.output; 
			double outNetH3=H3.output; 

			out.getOutput(outNetH1,outNetH2,outNetH3);
			double result=out.output; 
			double expected=trainingData[3][i]; 

			error=sqrt(abs(result-expected)); 


			// Back Propagation

			double adjustment1=(result-expected)*(out.output)*(1-(out.output))*H1.output;  
			double adjustment2=(result-expected)*(out.output)*(1-(out.output))*H2.output; 
			double adjustment3=(result-expected)*(out.output)*(1-(out.output))*H3.output;   
			out.updateWeight(adjustment1,adjustment2, adjustment3); 

			/*
			std::cout<<out.w1<<" "<<out.w2<<" "<<out.w3; 
			std::cin.get();
			*/ 

			// Weight adjustment -- Two

			H1.updateWeight(adjustment1*trainingData[0][i], 
			adjustment1*trainingData[1][i],
			adjustment1*trainingData[2][i]);

			H2.updateWeight(adjustment2*trainingData[0][i], 
			adjustment2*trainingData[1][i],
			adjustment2*trainingData[2][i]);

			H3.updateWeight(adjustment3*trainingData[0][i], 
			adjustment3*trainingData[1][i],
			adjustment3*trainingData[2][i]);

			totalError=totalError+error;
		}
		totalError=totalError/45; 

		std::cout<<totalError<<" "<<count<<std::endl;  
		
			}
		
	}

   void calculateFinal(double x, double y, double z)
   {
   	    double total1=H1.w1*x+H1.w2*y+H1.w3*z+H1.bias; 
		double output1=1/(1+exp((-1)*total1));

   	    double total2=H2.w1*x+H2.w2*y+H2.w3*z+H1.bias; 
		double output2=1/(1+exp((-1)*total2));

		double total3=H2.w1*x+H2.w2*y+H2.w3*z+H1.bias; 
		double output3=1/(1+exp((-1)*total3));

		double total4=out.w1*output1+out.w2*output2+out.w3*output3+out.bias;
		finalOutput=1/(1+exp((-1)*total4));

		std::cout<<finalOutput<<std::endl; 
   }
}; 

#endif 