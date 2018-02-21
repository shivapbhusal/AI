/*
Perceptron implementation in C++ 
CS 6200
Shiva Bhusal, Bowling Green State University

*/

#ifndef GENERATE_H 
#define GENERATE_H
#include<iostream> 

class Generate {
	private:
		double x=0,y=0,z=0; 
  
    public:
    	double trainingSet[4][30]= {
                     { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
                      };

	Generate(double c1,double c2,double c3) // Take the center of the circles
	{
		x=c1; 
		y=c2; 
		z=c3; 
	}; 

	void setDataValues()
	{
		int j=0; 
        double i=0.4; 
	    while (j<=8)
	{
		trainingSet[0][j]=x+i;
		trainingSet[0][j+1]=x-i; 
		i=i+0.4;
		j=j+2; 
	}

  j=10; 
  i=0.4; 
	while (j<=18)
	{
		trainingSet[1][j]=y+i;
		trainingSet[1][j+1]=y-i; 
		i=i+0.4;
		j=j+2; 
	}

    j=20; 
    i=0.4; 
	while (j<=28)
	{
		trainingSet[2][j]=z+i;
		trainingSet[2][j+1]=z-i; 
		i=i+0.4;
		j=j+2; 
	}


	}
		

}; 

#endif 
