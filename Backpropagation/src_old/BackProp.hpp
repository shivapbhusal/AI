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
	double const THETA=2; 
	double w1; 
	double w2; 
	double w3; 
	double bias=0.9; 
	double total;  
	double output;

	Node(double wght1, double wght2, double wght3)
	{
		w1=wght1; 
		w2=wght2; 
		w3=wght3; 
	}

	void updateWeight(double adj1, double adj2, double adj3)
	{
		
		w1=w1-THETA*adj1; 	
		w2=w2-THETA*adj2; 
		w3=w3-THETA*adj3; 
	}

	double getOutput(double x, double y, double z)
	{
		total=w1*x+w2*y+w3*z+bias; 
		output=1/(1+exp((-1)*total));

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
		Node *H1=new Node(0.5, 0.9,0.1); 
		Node *H2=new Node(0.2, 0.1, 0.6); 
		Node *H3=new Node(0.7,0.8,0.9); 

		//Create three output Nodes. 
	    Node *out1=new Node(0.1,0.3,0.9); 
	    Node *out2=new Node(0.9,0.4,0.4); 
	    Node *out3=new Node(0.2,0.25,0.30); 


	void trainModel(double trainingData[3][45])
	{

		// Start of the Forward Pass 
		int count=0; 
		while (count<500000)
		{
		double expectedA=0, expectedB=0,expectedC=0; // Initialize  
		for (int i=0;i<45;i++)
		{
			if (i<15)
			{
				expectedA=1; 
				expectedB=-1; 
				expectedC=-1; 
			}

			else if ((i>=15) && (i<30))
			{
				expectedA=-1; 
				expectedB=1; 
				expectedC=-1; 

			}
			else
			{
				expectedA=-1; 
				expectedB=-1; 
				expectedC=1; 
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

			errorTotal=(errorA+errorB+errorC)/3; 

			// End of the Forward pass 

			// Start of the backward pass 

			double adj01=-(expectedA-resultA)*(out1->output)*(1-(out1->output))*H1->output; 
			double adj02=-(expectedA-resultA)*(out1->output)*(1-(out1->output))*H2->output;  
			double adj03=-(expectedA-resultA)*(out1->output)*(1-(out1->output))*H3->output;  
			out1->updateWeight(adj01,adj02,adj03);  

			double adj11=-(expectedA-resultA)*(out2->output)*(1-(out2->output))*H1->output; 
			double adj12=-(expectedA-resultA)*(out2->output)*(1-(out2->output))*H2->output;  
			double adj13=-(expectedA-resultA)*(out2->output)*(1-(out2->output))*H3->output;  
			out2->updateWeight(adj11,adj12,adj13);  

			double adj21=-(expectedA-resultA)*(out3->output)*(1-(out3->output))*H1->output; 
			double adj22=-(expectedA-resultA)*(out3->output)*(1-(out3->output))*H2->output;  
			double adj23=-(expectedA-resultA)*(out3->output)*(1-(out3->output))*H3->output;  
			out3->updateWeight(adj21,adj22,adj23);  

			H1->updateWeight(adj01*trainingData[0][i],adj11*trainingData[1][i], adj21*trainingData[2][i]); 
			H2->updateWeight(adj02*trainingData[0][i],adj12*trainingData[1][i], adj22*trainingData[2][i]); 
			H3->updateWeight(adj03*trainingData[0][i],adj13*trainingData[1][i], adj23*trainingData[2][i]); 

			//End of the backward pass
		}
		count=count+1; 
		std::cout<<errorTotal<<" "<<count<<std::endl; 
	}
}

   void calculateFinal(double x, double y, double z)
   {
   	    double total1=H1->w1*x+H1->w2*y+H1->w3*z+H1->bias; 
		double output1=(1/(1+exp(total1))); 

   	    double total2=H2->w1*x+H2->w2*y+H2->w3*z+H1->bias; 
		double output2=(1/(1+exp(-total2)));

		double total3=H2->w1*x+H2->w2*y+H2->w3*z+H1->bias; 
		double output3=(1/(1+exp(-total3)));

		double total4=out1->w1*output1+out1->w2*output2+out1->w3*output3+out1->bias;
		finalOutput1=(1/(1+exp(-total4)));

		double total5=out2->w1*output1+out2->w2*output2+out2->w3*output3+out2->bias;
		finalOutput2=(1/(1+exp(-total5)));

		double total6=out3->w1*output1+out3->w2*output2+out3->w3*output3+out3->bias;
		finalOutput3=(1/(1+exp(-total6)));

		//std::cout<<finalOutput1<<" "<<finalOutput2<<" "<<finalOutput3<<std::endl; 
		classify(finalOutput1, finalOutput2, finalOutput3); 
   }

   void classify(double finalOutput1, double finalOutput2, double finalOutput3)
   {
   	   if (finalOutput1>=finalOutput2)
   	   {
   	   	if (finalOutput1>=finalOutput3)
   	   	{
   	   		std::cout<<"Class A"<<std::endl; 
   	   	}
   	   	else {
   	   		if (finalOutput2>=finalOutput3){
   	   			std::cout<<"Class B"<<std::endl;  
   	   		}
   	   		else {
   	   			std::cout<<"Class C"<<std::endl; 
   	   		}
   	   	}
   	   }
   	   else {
   	   	if (finalOutput2>=finalOutput3)
   	   	{
   	   		std::cout<<"Class B"<<std::endl; 
   	   	}
   	   	else {
   	   		std::cout<<"Class C"<<std::endl; 
   	   	}

   	   }
   	}
}; 

#endif 