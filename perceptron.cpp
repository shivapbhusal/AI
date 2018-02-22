/*
Perceptron implementation in C++
Shiva Bhusal 
CS 6200, Bowling Green State University

*/ 

#include<iostream>
#include "perceptron.hpp"
#include "generateData.hpp"

int  main()
{

Perceptron P1(0.5,0); 
Generate G(0,0,0); 
P1.trainModel(G.trainingSet); 


for (int i=0;i<=3;i++)
{
   double  resultA=P1.getFinalResult(G.trainingSet[0][i],G.trainingSet[1][i],G.trainingSet[2][i]);
   
   if (resultA>0){
    std::cout<<"class A"; 
   }

}
  return 0;


}
