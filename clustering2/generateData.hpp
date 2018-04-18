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
	double x=0; 
	double y=0;  
  
    public:
    	double trainingSet[2][10]= {
                     { 0,0,0,0,0,0,0,0,0,0},
                     { 0,0,0,0,0,0,0,0,0,0}
                      };

	Generate(double c1,double c2) // Take the center of the circles
	{
		x=c1; 
		y=c2; 
	}; 

// Sets respective values of the points around the center with gradual increment. 
	void setDataValues()
	{
		int j=0; 
        double i=0.5; 
	    while (j<5)
	{
		trainingSet[0][j]=x+i;
		trainingSet[0][j+1]=x-i; 
		i=i+0.4;
		j=j+2; 
	}

    j=5; 
    i=0.4; 
	while (j<10)
	{
		trainingSet[1][j]=y+i;
		trainingSet[1][j+1]=y-i; 
		i=i+0.4;
		j=j+2; 
	}

	std::cout<<"10 dataSets generated"<<std::endl;  

	}

	void readDataValues()
	{

	for (int k=0;k<10;k++) // Read all the dataSets
    {
  	  std::cout<<trainingSet[0][k]<<" "<<trainingSet[1][k]<<std::endl; 
    }

	}
		

}; 

#endif 
