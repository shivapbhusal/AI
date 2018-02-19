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
	Perceptron(double inputRate, double inputThreshhold)
	{
		learningRate=inputRate; 
		threshold=inputThreshhold; 
	}; 

	void trainModel(std::vector<double> X,std::vector<double> Y, std::vector<double> Z, std::vector<double> Outputs)
	{
		std::cout<<"Hello Train!"; 

	}; 

	double calculateOutput(double x, double y, double z)
	{
		return 2.00; 

	}; 

}; 

#endif 
