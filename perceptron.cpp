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

int trainingSetC[4][4]= {
  { 100,100,100,100 },
  { 0,1,2,3 },
  { 0,0,0,0 },
  { 1,1,1,1 }
};


Perceptron P1(0.5,0); 
P1.trainModel(trainingSetA); 

Perceptron P2(0.5,0); 
P2.trainModel(trainingSetB); 

Perceptron P3(0.5,0); 
P3.trainModel(trainingSetC); 

for (int i=0;i<=3;i++)
{
   double  resultA=P1.getFinalResult(trainingSetA[0][i],trainingSetA[1][i],trainingSetA[2][i]);
   double  resultB=P2.getFinalResult(trainingSetA[0][i],trainingSetA[1][i],trainingSetA[2][i]);
   double resultC=P3.getFinalResult(trainingSetA[0][i],trainingSetA[1][i],trainingSetA[2][i]);
   
   if (resultA>resultB and resultA>resultC)
   {
   	std::cout<<"Class A"; 
   }
   else if (resultB>resultA and resultB>resultC)
   {
    std::cout<<"Class B"; 
   }
   else {
   	std::cout<<"Class C"; 
   }

}
  return 0;

}
