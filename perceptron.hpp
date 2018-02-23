/*
Perceptron implementation in C++ 
CS 6200
Shiva Bhusal, Bowling Green State University

*/

#ifndef PERCEPTRON_H 
#define PERCEPTRON_H
#include<iostream> 

class Perceptron {
private:
	double learningRate; 
	double threshold;
    double weights[4]={0,0,0,0};  // Initialize all weights to 0 
  
public:
	Perceptron(double rate, double threshhold) // Initialize a perceptron with threshhold and learning rate. 
	{
		learningRate=rate; 
		threshold=threshold; 
	}; 

	void trainModel(double trainingData[4][30])
	{
		int count=0; // Check for how many consecutive times there will be no changes in the weights.
		int N=0; // No of iterations taken for training  

		while(count<=15)
		{
			for (int i=0;i<15;i++)
			{
			   double currentResult=getResult(trainingData[0][i],trainingData[1][i],trainingData[2][i]); 
			   double error=trainingData[3][i]-currentResult; 
			   if (error==0){
			   	count=count+1;
			   	N=N+1;  
			   }
			   else {
			     weights[0]=weights[0]+learningRate*error*trainingData[0][i]; 
                 weights[1]=weights[1]+learningRate*error*trainingData[1][i]; 
                 weights[2]=weights[2]+learningRate*error*trainingData[2][i]; 
                 weights[3]=weights[3]+learningRate*error; 
                 N=N+1;
                 count=0;  
			   }
			   
			 }
			   
		}

		std::cout<<"Trainining Succesful using first 15 datasets"<<std::endl; 
		std::cout<<"Total no of Iterations: "<<N<<std::endl<<std::endl; 

	}; 

	double getResult(double x, double y, double z)
	{
		double result=x*weights[0]+y*weights[1]+z*weights[2]+weights[3]; 
		if (result<=0)
		{
			return 0; 
		}
		else {
			return 1; 
		}

	}; 

	double getFinalResult(double x, double y, double z)
	{
		double result=x*weights[0]+y*weights[1]+z*weights[2]+weights[3];
		return result;  

	}

}; 

#endif 
