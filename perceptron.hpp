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
    const int MAX=8; 

public:
	Perceptron(double rate, double threshhold)
	{
		learningRate=rate; 
		threshold=threshold; 
	}; 

	void trainModel(int trainingData[4][8])
	{
		std::cout<<"Training started !"; 

	}; 

	double calculateOutput(double x, double y, double z)
	{
		return 2.00; 

	}; 

}; 

#endif 
