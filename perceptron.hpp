/* Header file for the perceptron

Created By: Shiva Bhusal, 
CS 6200, BGSU 

*/
#ifndef PERCEPTRON_H 
#define PERCEPTRON_H
#include<iostream> 
#include<vector>

class Perceptron {
private:
	double learningRate; 
	double threshold;
    std::vector<double> weights;
    const static int MAX=8; 

public:
	Perceptron(double rate, double threshhold)
	{
		learningRate=rate; 
		threshold=threshold; 
	}; 

	void trainModel(int trainingData[4][8])
	{
		for(int i=0;i<4;i++){
			for (int j=0;j<8;j++){
				std::cout<<trainingData[i][j]<<" "; 
			}
			std::cout<<"\n"; 
		}

	}; 

	double calculateOutput(double x, double y, double z)
	{
		return 2.00; 

	}; 

}; 

#endif 
