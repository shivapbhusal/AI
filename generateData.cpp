/* A program to generate test data for the spheres 

CS 6200, Bowling Green State University 
Shiva Bhusal 
*/ 

#include<iostream>
#include"generateData.hpp"

int main()
{

Generate G(0,0,0); 
G.setDataValues();
double trainingSetB[4][30]={G.trainingSet[4][30]}; 

for (int k=0;k<=29;k++)
  {
  	std::cout<<G.trainingSet[0][k]<<" "<<G.trainingSet[1][k]<<" "<<G.trainingSet[2][k]<<" "<<G.trainingSet[3][k]; 
  	std::cout<<std::endl; 
  }

 std::cout<<"30 dataSets created"; 

return 0; 
}
