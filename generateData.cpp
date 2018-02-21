/* A program to generate test data for the spheres 

CS 6200, Bowling Green State University 
Shiva Bhusal 
*/ 

#include<iostream>
#include"generateData.hpp"

int main()
{
	double  x=0; 
	double  y=0; 
	double  z=0; 
	
  double trainingSetA[4][30]= {
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
  };

  int j=0; 
  double i=0.4; 
	while (j<=8)
	{
		trainingSetA[0][j]=x+i;
		trainingSetA[0][j+1]=x-i; 
		i=i+0.4;
		j=j+2; 
	}

  j=10; 
  i=0.4; 
	while (j<=18)
	{
		trainingSetA[1][j]=y+i;
		trainingSetA[1][j+1]=y-i; 
		i=i+0.4;
		j=j+2; 
	}

    j=20; 
    i=0.4; 
	while (j<=28)
	{
		trainingSetA[2][j]=z+i;
		trainingSetA[2][j+1]=z-i; 
		i=i+0.4;
		j=j+2; 
	}

  for (int k=0;k<=29;k++)
  {
  	std::cout<<trainingSetA[0][k]<<" "<<trainingSetA[1][k]<<" "<<trainingSetA[2][k]<<" "<<trainingSetA[3][k]; 
  	std::cout<<std::endl; 
  }

Generate G(0,0,0); 
G.setDataValues();
double trainingSetB[4][30]={G.trainingSet[4][30]}; 

for (int k=0;k<=29;k++)
  {
  	std::cout<<trainingSetB[0][k]<<" "<<trainingSetB[1][k]<<" "<<trainingSetB[2][k]<<" "<<trainingSetB[3][k]; 
  	std::cout<<std::endl; 
  }

return 0; 
}
