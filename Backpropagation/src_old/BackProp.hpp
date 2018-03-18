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
		double finalOutput1=0; 
		double finalOutput2=0; 
		double finalOutput3=0; 

		double errorTotal=1;
		// Create three hidden nodes. 
		Node *H1=new Node(); 
		Node *H2=new Node(); 
		Node *H3=new Node(); 

		//Create three output Nodes. 
	    Node *out1=new Node(); 
	    Node *out2=new Node(); 
	    Node *out3=new Node(); 


	void trainModel(double trainingData[3][45])
	{
		int count=0; 
		while (errorTotal>0.1)
		{
			count=count+1; 
		double expectedA=0, expectedB=0,expectedC=0; // Initialize  
		for (int i=0;i<45;i++)
		{
			if (i<15)
			{
				expectedA=0.8; 
				expectedB=0.1; 
				expectedC=0.1; 
			}

			else if ((i>=15) && (i<30))
			{
				expectedA=0.1; 
				expectedB=0.8; 
				expectedC=0.1; 

			}
			else if ((i>=30) && (i<45)) 
			{
				expectedA=0.1; 
				expectedB=0.1; 
				expectedC=0.8; 
			}
			else {
				std::cout<<"Extra training dataSets detected."; 
			}
			double outNetH1=H1->getOutput(trainingData[0][i],trainingData[1][i],trainingData[2][i]); 
			double outNetH2=H2->getOutput(trainingData[0][i],trainingData[1][i],trainingData[2][i]); 
			double outNetH3=H3->getOutput(trainingData[0][i],trainingData[1][i],trainingData[2][i]); 

			double resultA=out1->getOutput(outNetH1,outNetH2,outNetH3);
			double resultB=out2->getOutput(outNetH1,outNetH2,outNetH3); 
			double resultC=out3->getOutput(outNetH1,outNetH2,outNetH3);

			double errorA=pow((resultA-expectedA),1/2)/2; 
			double errorB=pow((resultB-expectedB),1/2)/2; 
			double errorC=pow((resultC-expectedC),1/2)/2; 

			// Weight adjustment --One 

			errorTotal=errorA+errorB+errorC; 

			double adjustment=-(expectedA-resultA)*(out1->output)*(1-(out1->output))*H1->output;  
			out1->updateWeight(adjustment,1); 
			out1->updateWeight(adjustment,2);
			out1->updateWeight(adjustment,3); 

			adjustment=-(expectedA-resultA)*(out2->output)*(1-(out2->output))*H2->output;  
			out2->updateWeight(adjustment,1); 
			out2->updateWeight(adjustment,2);
			out2->updateWeight(adjustment,3); 

			adjustment=-(expectedA-resultA)*(out3->output)*(1-(out3->output))*H3->output;  
			out3->updateWeight(adjustment,1); 
			out3->updateWeight(adjustment,2);
			out3->updateWeight(adjustment,3); 

			// Weight adjustment -- Two

			adjustment=(H1->w1)*-(expectedA-resultA)*(out1->output)*(1-(out1->output));  
			H1->updateWeight(adjustment,1); 
			H1->updateWeight(adjustment,2);
			H1->updateWeight(adjustment,3); 

			adjustment=(H2->w1)*-(expectedA-resultA)*(out2->output)*(1-(out2->output));  
			H2->updateWeight(adjustment,1); 
			H2->updateWeight(adjustment,2);
			H2->updateWeight(adjustment,3); 

			adjustment=(H2->w1)*-(expectedA-resultA)*(out3->output)*(1-(out3->output));  
			H3->updateWeight(adjustment,1); 
			H3->updateWeight(adjustment,2);
			H3->updateWeight(adjustment,3); 

		}
		std::cout<<errorTotal<<" "<<count<<std::endl; 
	}
}

   void calculateFinal(double x, double y, double z)
   {
   	    double total1=H1->w1*x+H1->w2*y+H1->w3*z+H1->bias; 
		double output1=1/(1+pow(2.7,total1));

   	    double total2=H2->w1*x+H2->w2*y+H2->w3*z+H1->bias; 
		double output2=1/(1+pow(2.7,total2));

		double total3=H2->w1*x+H2->w2*y+H2->w3*z+H1->bias; 
		double output3=1/(1+pow(2.7,total3));

		double total4=out1->w1*output1+out1->w2*output2+out1->w3*output3+out1->bias;
		finalOutput1=1/(1+pow(2.7,total4));

		double total5=out2->w1*output1+out2->w2*output2+out2->w3*output3+out2->bias;
		finalOutput2=1/(1+pow(2.7,total5));

		double total6=out3->w1*output1+out3->w2*output2+out3->w3*output3+out3->bias;
		finalOutput3=1/(1+pow(2.7,total6));

		std::cout<<finalOutput1<<" "<<finalOutput2<<" "<<finalOutput3<<std::endl; 
   }
}; 

#endif 