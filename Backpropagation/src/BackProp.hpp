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
	double w1=0; 
	double w2=0; 
	double w3=0; 
	double bias=0.2; 
	double total=0; 
	double output=0; 

    Node (double a, double b, double c, double d)
	{
		w1=a; 
		w2=b; 
		w3=c; 
		bias=d;  
	}

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
		output=(1/(1+pow(2.7,total)));
		return output;   
	}
}; 

class BackProp{

	public: 
		double errorTotal=1;
		// Create three hidden nodes. 
		Node *H1=new Node(0.1,0.1,0.1,0.1); 
		Node *H2=new Node(0.1,0.1,0.1,0.1); 
		Node *H3=new Node(0.1,0.1,0.1,0.1); 

		//Create three output Nodes. 
	    Node *out1=new Node(0.5,0.6,0.7,0.1); 
	    Node *out2=new Node(0.5,0.6,0.7,0.1); 
	    Node *out3=new Node(0.5,0.6,0.7,0.1); 


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
				expectedA=1; 
				expectedB=0; 
				expectedC=0; 
			}

			else if ((i>=15) && (i<30))
			{
				expectedA=0; 
				expectedB=1; 
				expectedC=0; 

			}
			else if ((i>=30) && (i<45)) 
			{
				expectedA=0; 
				expectedB=0; 
				expectedC=1; 
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

			double errorA=pow((resultA-expectedA),2)/2; 
			double errorB=pow((resultB-expectedB),2)/2; 
			double errorC=pow((resultC-expectedC),2)/2; 

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
			out1->updateWeight(adjustment,1); 
			out1->updateWeight(adjustment,2);
			out1->updateWeight(adjustment,3); 

			adjustment=(H2->w1)*-(expectedA-resultA)*(out2->output)*(1-(out2->output));  
			out1->updateWeight(adjustment,1); 
			out1->updateWeight(adjustment,2);
			out1->updateWeight(adjustment,3); 

			adjustment=(H2->w1)*-(expectedA-resultA)*(out3->output)*(1-(out3->output));  
			out1->updateWeight(adjustment,1); 
			out1->updateWeight(adjustment,2);
			out1->updateWeight(adjustment,3); 

		}
		std::cout<<H1->w1<<H1->w2<<H1->w3; 
		std::cout<<errorTotal<<" "<<count<<std::endl; 
	}
}
}; 

#endif 