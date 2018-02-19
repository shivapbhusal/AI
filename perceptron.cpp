#include<iostream>
#include "perceptron.hpp"

int  main()
{
	Perceptron P;
	P.trainModel(); 
	P.readDataSet(); 
	P.dotProduct(); 

}
