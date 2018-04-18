/*
Main file for cpp implementation of KMeans Clustering. 
*/

#include<iostream>
#include "KMeans.hpp"
#include "generateData.hpp"
int  main()
{
std::cout<<"K means clustering"<<std::endl<<std::endl; 

Generate A(0,50); 
A.setDataValues(); // generates 30 datasets around the chosen center. 
A.readDataValues(); 

Generate B(50,50); 
B.setDataValues();
B.readDataValues(); 

Generate C(50,0);
C.setDataValues(); 
C.readDataValues(); 

LinkedList L; 
for (int i=0;i<=10;i++)
  {
    L.insert(A.trainingSet[1][i+1],A.trainingSet[2][i+1]); 
    L.insert(B.trainingSet[1][i+1],B.trainingSet[2][i+1]); 
    L.insert(C.trainingSet[1][i+1],C.trainingSet[2][i+1]); 
  }

  KMeans *kmeans=new KMeans(2); // customize the clustering algorithm with necessary value of K. 

  Coordinate c=kmeans->runAlgorithm(L); 

  std::cout<<c.x_value<<std::endl; 
  std::cout<<c.y_value<<std::endl; 

}
