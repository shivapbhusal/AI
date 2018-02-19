/* Header file for the perceptron

Created By: Shiva Bhusal, 
CS 6200, BGSU 

*/
#ifndef PERCEPTRON_H 
#define PERCEPTRON_H 
#include<vector>

class Perceptron {
private:
	double learningRate; 
	double threshold;
    std::vector<double> weights;

public:
	Perceptron()
	{
		std::cout<<"Create new Perceptron"; 

	}; 

	void trainModel()
	{
		std::cout<<"Hello Train!"; 

	}; 

	void readDataSet()
	{
		std::cout<<"Read Dataset"; 

	};

	void dotProduct()
	{
		std::cout<<"Perform dot product"; 

	}; 

}; 

#endif 
