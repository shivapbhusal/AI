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
    double expectedOutput[45]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  
public:
	double weights[4]={0,0,0,0};  // Initialize all weights to 0 
	Perceptron(double rate, double threshhold, char classType) // Initializes a perceptron with threshhold and learning rate. 
	{
		learningRate=rate; 
		threshold=threshold; 
		if (classType=='A'){
			for (int i=0;i<15;i++)
			{
				expectedOutput[i]=1; 
			}
		}
		else if (classType=='B'){
			for (int i=15;i<30;i++)
			{
				expectedOutput[i]=1; 
			}
		}
		else if (classType=='C'){
			for (int i=30;i<45;i++)
			{
				expectedOutput[i]=1; 
			}
		}
		else {
			std::cout<<"check the classType, it should be A, B or C"; 
		}
	}; 

	void trainModel(double trainingData[3][45])
	{
		int count=0; // Check for how many consecutive times there will be no changes in the weights.
		int N=0; // No of iterations taken for training  

		while(count<=45)
		{
			for (int i=0;i<45;i++)
			{
			   double currentOutput=getResult(trainingData[0][i],trainingData[1][i],trainingData[2][i]); 
			   double error=expectedOutput[i]-currentOutput; 
			   if (error==0){
			   	count=count+1; 
			   }
			   else {
			     weights[0]=weights[0]+learningRate*error*trainingData[0][i]; // Make changes in the weight if there is an error. 
                 weights[1]=weights[1]+learningRate*error*trainingData[1][i]; 
                 weights[2]=weights[2]+learningRate*error*trainingData[2][i]; 
                 weights[3]=weights[3]+learningRate*error; 
                 count=0;  
			   }

			   N=N+1;
			   checkIteration(N);  
			   
			 }
			   
		}

		std::cout<<"Trainining Succesful using first 15 datasets of each classes"<<std::endl; 
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

	void checkIteration(int N)
	{
		if (N>1000000000){
			std::cout<<"Warning ! Stop !"<<N<<" Iterations completed"<<std::endl;  
		}
		
	}

}; 

#endif 
