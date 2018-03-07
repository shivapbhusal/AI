/*
Backpropagation implementation in C++
Author: Shiva Bhusal, CS 6200

*/ 

#include<iostream>
#include "generateData.hpp"
#include "BackProp.hpp"

int  main()
{

std::cout<<"Centers of spheres:"<<"(0,50,-50),(-50,-50,-50),(50,50,50)"<<std::endl<<std::endl; 

Generate A(0,50,-50); 
A.setDataValues(); // generates 30 datasets around the chosen center. 
A.readDataValues(); 

Generate B(-50,-50,-50); 
B.setDataValues();
B.readDataValues(); 

Generate C(50,50,50);
C.setDataValues(); 
C.readDataValues(); 

}
