/*
Perceptron implementation in C++
Shiva Bhusal 
CS 6200, Bowling Green State University

*/ 

#include<iostream>
#include "perceptron.hpp"

int  main()
{
  int trainingData[4][8]= {
  { 0,0,0,1,7,7,7,7 },
  { 0,1,2,3,0,1,2,3 },
  { 0,0,0,0,0,0,0,0 },
  { 1,1,1,1,0,0,0,0 }
};

Perceptron P(0.5,0); 
P.trainModel(trainingData); 

for (int i=-50;i<=50;i++)
{
	for (int j=-50;i<=50;j++)
	{
		std::string dataClass=P.classify(i,j,0);
        std::cout<<dataClass;  

	}
}

  return 0;

}
