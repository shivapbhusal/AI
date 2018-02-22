/*
Perceptron implementation in C++
Shiva Bhusal 
CS 6200, Bowling Green State University

*/ 

#include<iostream>
#include "perceptron.hpp"
#include "generateData.hpp"
#include "Classify.hpp"

int  main()
{

Perceptron P1(0.5,0); 
Generate A(0,50,-50); 
A.setDataValues();
P1.trainModel(A.trainingSet); 

Perceptron P2(0.5,0); 
Generate B(-50,-50,-50); 
B.setDataValues();
P2.trainModel(B.trainingSet); 

Perceptron P3(0.5,0); 
Generate C(50,50,50);
C.setDataValues(); 
P3.trainModel(C.trainingSet); 

Classify classify; 

std::cout<<"Testing Result for second half of Class A dataset: "; 
for (int i=15;i<30;i++) // For A 
{
   double  resultA=P1.getFinalResult(A.trainingSet[0][i],A.trainingSet[1][i],A.trainingSet[2][i]);
   double  resultB=P2.getFinalResult(A.trainingSet[0][i],A.trainingSet[1][i],A.trainingSet[2][i]);
   double  resultC=P3.getFinalResult(A.trainingSet[0][i],A.trainingSet[1][i],A.trainingSet[2][i]); 
   std::cout<<A.trainingSet[0][i]<<","<<A.trainingSet[1][i]<<","<<A.trainingSet[2][i]<<": "; 
   std::cout<<classify.classifyPoints(resultA,resultB,resultC)<<std::endl; 
   
   }


std::cout<<"Testing Result for second half of Class B dataset: "; 
for (int i=15;i<30;i++) // For A 
{
   double  resultA=P1.getFinalResult(B.trainingSet[0][i],B.trainingSet[1][i],B.trainingSet[2][i]);
   double  resultB=P2.getFinalResult(B.trainingSet[0][i],B.trainingSet[1][i],B.trainingSet[2][i]);
   double  resultC=P3.getFinalResult(B.trainingSet[0][i],B.trainingSet[1][i],B.trainingSet[2][i]); 
   std::cout<<B.trainingSet[0][i]<<","<<B.trainingSet[1][i]<<","<<B.trainingSet[2][i]<<": ";
   std::cout<<classify.classifyPoints(resultA,resultB,resultC)<<std::endl; 

   }

   std::cout<<"Testing Result for second half of Class C dataset: "; 
for (int i=15;i<30;i++) // For A 
{
   double  resultA=P1.getFinalResult(C.trainingSet[0][i],C.trainingSet[1][i],C.trainingSet[2][i]);
   double  resultB=P2.getFinalResult(C.trainingSet[0][i],C.trainingSet[1][i],C.trainingSet[2][i]);
   double  resultC=P3.getFinalResult(C.trainingSet[0][i],C.trainingSet[1][i],C.trainingSet[2][i]); 
   std::cout<<C.trainingSet[0][i]<<","<<C.trainingSet[1][i]<<","<<C.trainingSet[2][i]<<": ";
   std::cout<<classify.classifyPoints(resultA,resultB,resultC)<<std::endl; 

   }
}
