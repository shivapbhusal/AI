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
   std::cout<<"Centers of spheres:"<<"(0,50,-50),(-50,-50,-50),(50,50,50)"<<std::endl<<std::endl; 

std::cout<<"Class A"<<std::endl; 
Generate A(0,50,-50); 
A.setDataValues();
A.trainingSet[0][14]=50; 
A.trainingSet[1][14]=50; 
A.trainingSet[2][14]=50; 
A.trainingSet[0][29]=90; 
A.trainingSet[1][29]=90; 
A.trainingSet[2][29]=100;
A.readDataValues(); 

std::cout<<"Class B"<<std::endl; 
Generate B(-50,-50,-50); 
B.setDataValues();
B.trainingSet[0][14]=99; 
B.trainingSet[1][14]=99; 
B.trainingSet[2][14]=99; 
B.trainingSet[0][29]=101; 
B.trainingSet[1][29]=101; 
B.trainingSet[2][29]=101; 
B.readDataValues(); 

std::cout<<"Class C"<<std::endl; 
Generate C(50,50,50);
C.setDataValues(); 
C.trainingSet[0][14]=0; 
C.trainingSet[1][14]=60; 
C.trainingSet[2][14]=-50;
C.trainingSet[0][29]=0; 
C.trainingSet[1][29]=61; 
C.trainingSet[2][29]=-50; 
C.readDataValues(); 

double finalTrainingSet[3][45]=
{
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

// Get the training DataSet in organized form 

for (int i=0;i<15;i++)
{
   finalTrainingSet[0][i]=A.trainingSet[0][i];  
   finalTrainingSet[1][i]=A.trainingSet[1][i];  
   finalTrainingSet[2][i]=A.trainingSet[2][i]; 
   finalTrainingSet[0][i+15]=B.trainingSet[0][i]; 
   finalTrainingSet[1][i+15]=B.trainingSet[1][i]; 
   finalTrainingSet[2][i+15]=B.trainingSet[2][i]; 
   finalTrainingSet[0][i+30]=C.trainingSet[0][i]; 
   finalTrainingSet[1][i+30]=C.trainingSet[1][i]; 
   finalTrainingSet[2][i+30]=C.trainingSet[2][i]; 
}

// Train model with class A points 
std::cout<<std::endl<<"Perceptron 1 --Seprating A from others"<<std::endl; 
Perceptron P1(0.5,0,'A'); 
P1.trainModel(finalTrainingSet); // Array is passed to the training model. The training model uses only first 15 datasets. 

std::cout<<"Weights are: "<<std::endl; 
for (int i=0;i<=3;i++)
{
   std::cout<<P1.weights[i]<<" ";
}
std::cout<<std::endl<<std::endl; 

// Train model with class B points 
std::cout<<"Perceptron 2--Separating B from others"<<std::endl; 
Perceptron P2(0.5,0,'B'); 
P2.trainModel(finalTrainingSet); 

std::cout<<"Weights are: "<<std::endl; 
for (int i=0;i<=3;i++)
{
   std::cout<<P2.weights[i]<<" ";
}
std::cout<<std::endl<<std::endl; 

// Train model with class C points 
std::cout<<"Perceptron 3--Separating C from others"<<std::endl; 
Perceptron P3(0.5,0,'C'); 
P3.trainModel(finalTrainingSet); 

std::cout<<"Weights are: "<<std::endl; 
for (int i=0;i<=3;i++)
{
   std::cout<<P3.weights[i]<<" ";
}
std::cout<<std::endl<<std::endl; 

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
