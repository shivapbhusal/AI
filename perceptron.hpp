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

	void trainModel(int trainingData[4][8])
	{
		int count=0; // Check for how many consecutive times there will be no changes in the weights.
		int N=0; // No of iterations taken for training  

		while (count<10)
		{
			for (int i=0;i<8;i++)
			{
			   double currentResult=getResult(trainingData[i][0],trainingData[i][1],trainingData[i][2]); 
			   if (currentResult<=0)
			   {
			   double error=trainingData[i][3]-currentResult; 
			   weights[0]=weights[0]+learningRate*error*trainingData[i][0]; 
               weights[1]=weights[1]+learningRate*error*trainingData[i][1]; 
               weights[2]=weights[2]+learningRate*error*trainingData[i][2]; 
               weights[3]=weights[3]+learningRate*error; 
               count=0; 
			   }
			   else {
			   	count=count+1; 
			   }
			   N=N+1; 
			}
		}

		std::cout<<"Training successful with " <<N<<" iterations"<<"\n"; 

	}; 

	double getResult(double x, double y, double z)
	{
		double result=x*weights[0]+y*weights[1]+z*weights[2]+weights[3]; 
		return result; 

	}; 

	std::string classify(double x, double y, double z)
	{
		double result=getResult(x,y,z); 
		if (result>0)
		{
			return "A"; 
		}
		else {
			return "B"; 
		}
	}

}; 

#endif 
