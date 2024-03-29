/*
Class created for data generation  
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
    	double trainingSet[3][30]= {
                     { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
                      };

	Generate(double c1,double c2,double c3) // Take the center of the circles
	{
		x=c1; 
		y=c2; 
		z=c3; 

	for (int k=0;k<=29;k++) // Set all the values with the centers of circle 
    {
  	trainingSet[0][k]=x; 
  	trainingSet[1][k]=y; 
  	trainingSet[2][k]=z; 
    }

	}; 

// Sets respective values of the points around the center with gradual increment. 
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

	std::cout<<"30 dataSets generated"<<std::endl;  

	}

	void readDataValues()
	{

	for (int k=0;k<=29;k++) // Read all the dataSets
    {
  	  std::cout<<trainingSet[0][k]<<" "<<trainingSet[1][k]<<" "<<trainingSet[2][k]<<std::endl; 
    }

	}
		

}; 

#endif 
