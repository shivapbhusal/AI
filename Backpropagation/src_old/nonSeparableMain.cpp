/*
Backpropagation implementation in C++
Author: Shiva Bhusal, CS 6200
*/ 

#include<iostream>
#include "generateData.hpp"
#include "BackProp.hpp"
#include "Classify.hpp"

int  main()
{

std::cout<<"Centers of spheres:"<<"(0,50,-50),(-50,-50,-50),(50,50,50)"<<std::endl<<std::endl; 

Generate A(100,100,100); 
A.setDataValues(); // generates 30 datasets around the chosen center.
A.trainingSet[0][14]=-50; 
A.trainingSet[1][14]=-50; 
A.trainingSet[2][14]=-50; 
A.trainingSet[0][29]=-49; 
A.trainingSet[1][29]=-49; 
A.trainingSet[2][29]=-49; 
A.readDataValues(); 

Generate B(-50,-50,-50); 
B.setDataValues();
B.trainingSet[0][14]=99; 
B.trainingSet[1][14]=99; 
B.trainingSet[2][14]=99; 
B.trainingSet[0][29]=101; 
B.trainingSet[1][29]=101; 
B.trainingSet[2][29]=101; 
B.readDataValues(); 

Generate C(50,50,50);
C.setDataValues(); 
C.trainingSet[0][14]=0; 
C.trainingSet[1][14]=60; 
C.trainingSet[2][14]=-50;
C.trainingSet[0][29]=0; 
C.trainingSet[1][29]=61; 
C.trainingSet[2][29]=-50; 
C.readDataValues(); 

std::cout<<"Press any key to start training !"; 
std::cin.get(); 

// Initial setup for Organized form of training dataset 
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

BackProp network; 
network.trainModel(finalTrainingSet);  // Train the Network using the training dataset 


// Test the model using the test dataset. 

for (int i=15;i<30;i++)
{
  std::cout<<A.trainingSet[0][i]<<","<<A.trainingSet[1][i]<<","<<A.trainingSet[2][i]<<" "<<"Actual Class:A "<<"Predicted Class: ";  
  network.calculateFinal(A.trainingSet[0][i],A.trainingSet[1][i],A.trainingSet[2][i]); 
}

for (int i=15;i<30;i++)
{
  std::cout<<B.trainingSet[0][i]<<","<<B.trainingSet[1][i]<<","<<B.trainingSet[2][i]<<" "<<"Actual Class:B "<<"Predicted Class: ";  
  network.calculateFinal(B.trainingSet[0][i],B.trainingSet[1][i],B.trainingSet[2][i]); 
}

for (int i=15;i<30;i++)
{
  std::cout<<C.trainingSet[0][i]<<","<<C.trainingSet[1][i]<<","<<C.trainingSet[2][i]<<" "<<"Actual Class:C "<<"Predicted Class: ";  
  network.calculateFinal(C.trainingSet[0][i],C.trainingSet[1][i],C.trainingSet[2][i]); 
}

}