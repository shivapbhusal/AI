/*
Main file for cpp implementation of KMeans Clustering. 
*/

#include<iostream>
//#include "KMeans.hpp"
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

/*LinkedList L; 
  /*for (int i=0;i<=10;i++)
  {
    L.insert(i,i+1); 
  }

  /*L.display();

  /*

  KMeans *kmeans=new KMeans(2);

  Coordinate c=kmeans->findCenter(L); 

  std::cout<<c.x_value<<std::endl; 
  std::cout<<c.y_value<<std::endl; 
  */

}
