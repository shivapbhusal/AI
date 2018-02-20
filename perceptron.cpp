/*
Perceptron implementation in C++
Shiva Bhusal 
CS 6200, Bowling Green State University

*/ 

#include<iostream>
#include "perceptron.hpp"

int  main()
{
  int trainingSetA[4][4]= {
  { 0,0,0,1},
  { 0,1,2,3},
  { 0,0,0,0},
  { 1,1,1,1}
};

int trainingSetB[4][4]= {
  { 7,7,7,7 },
  { 0,1,2,3 },
  { 0,0,0,0 },
  { 1,1,1,1 }
};

Perceptron P1(0.5,0); 
P1.trainModel(trainingSetA); 

Perceptron P2(0.5,0); 
P2.trainModel(trainingSetB); 

for (int i=0;i<=3;i++)
{
   double  resultA=P1.getFinalResult(trainingSetA[0][i],trainingSetA[1][i],trainingSetA[2][i]);
   double  resultB=P2.getFinalResult(trainingSetA[0][i],trainingSetA[1][i],trainingSetA[2][i]);

   if (resultA>=resultB)
   {
   	std::cout<<"Class A"; 
   }
   else {
   	std::cout<<"Class B"; 
   }

}
  return 0;

}
