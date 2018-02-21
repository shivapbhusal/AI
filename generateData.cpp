/* A program to generate test data for the spheres 

CS 6200, Bowling Green State University 
Shiva Bhusal 
*/ 

#include<iostream>

int main()
{
	int x=0; 
	int y=0; 
	int z=0; 
	
  int trainingSetA[4][30]= {
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
  };

  for (int j=0;j<15;j++)
   { 
	int i=0.5; 
	while (i<=2)
	{
		trainingSetA[0][j]=x+i;
		trainingSetA[0][j+1]=x-i;
		i=i+0.5; 
	}

}

return 0; 
}