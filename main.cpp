/*
Perceptron implementation in C++
Author: Shiva Bhusal, CS 6200
*/ 

#include<iostream>
#include "perceptron.hpp"
#include "generateData.hpp"
#include "Classify.hpp"

int  main()
{

std::cout<<"Centers of spheres:"<<"(0,50,-50),(-50,-50,-50),(50,50,50)"<<std::endl<<std::endl; 

// Train model with class A points 
std::cout<<"Class A"<<std::endl; 
Perceptron P1(0.5,0); 
Generate A(0,50,-50); 
A.setDataValues(); // generates 30 datasets around the chosen center. 
A.readDataValues(); 
P1.trainModel(A.trainingSet); // Array is passed to the training model. The training model uses only first 15 datasets. 

// Train model with class B points 
std::cout<<"Class B"<<std::endl; 
Perceptron P2(0.5,0); 
Generate B(-50,-50,-50); 
B.setDataValues();
B.readDataValues(); 
P2.trainModel(B.trainingSet); 

// Train model with class C points 
std::cout<<"Class C"<<std::endl; 
Perceptron P3(0.5,0); 
Generate C(50,50,50);
C.setDataValues(); 
C.readDataValues(); 
P3.trainModel(C.trainingSet); 

Classify classify; 

std::cout<<"Testing Result for second half of Class A dataset: "<<std::endl; 
for (int i=15;i<30;i++) // For A 
{
   double  resultA=P1.getFinalResult(A.trainingSet[0][i],A.trainingSet[1][i],A.trainingSet[2][i]);
   double  resultB=P2.getFinalResult(A.trainingSet[0][i],A.trainingSet[1][i],A.trainingSet[2][i]);
   double  resultC=P3.getFinalResult(A.trainingSet[0][i],A.trainingSet[1][i],A.trainingSet[2][i]); 
   std::cout<<A.trainingSet[0][i]<<","<<A.trainingSet[1][i]<<","<<A.trainingSet[2][i]<<": "; 
   std::cout<<classify.classifyPoints(resultA,resultB,resultC)<<std::endl; 
   
}
std::cout<<std::endl; 


std::cout<<"Testing Result for second half of Class B dataset: "<<std::endl; 
for (int i=15;i<30;i++) // For A 
{
   double  resultA=P1.getFinalResult(B.trainingSet[0][i],B.trainingSet[1][i],B.trainingSet[2][i]);
   double  resultB=P2.getFinalResult(B.trainingSet[0][i],B.trainingSet[1][i],B.trainingSet[2][i]);
   double  resultC=P3.getFinalResult(B.trainingSet[0][i],B.trainingSet[1][i],B.trainingSet[2][i]); 
   std::cout<<B.trainingSet[0][i]<<","<<B.trainingSet[1][i]<<","<<B.trainingSet[2][i]<<": ";
   std::cout<<classify.classifyPoints(resultA,resultB,resultC)<<std::endl; 

   }

std::cout<<std::endl; 

   std::cout<<"Testing Result for second half of Class C dataset: "<<std::endl; 
for (int i=15;i<30;i++) // For A 
{
   double  resultA=P1.getFinalResult(C.trainingSet[0][i],C.trainingSet[1][i],C.trainingSet[2][i]);
   double  resultB=P2.getFinalResult(C.trainingSet[0][i],C.trainingSet[1][i],C.trainingSet[2][i]);
   double  resultC=P3.getFinalResult(C.trainingSet[0][i],C.trainingSet[1][i],C.trainingSet[2][i]); 
   std::cout<<C.trainingSet[0][i]<<","<<C.trainingSet[1][i]<<","<<C.trainingSet[2][i]<<": ";
   std::cout<<classify.classifyPoints(resultA,resultB,resultC)<<std::endl; 

   }
}
