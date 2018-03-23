// A program to demonstrate pass by value and pass by reference 
//

#include<iostream>
using namespace std; 

void multiply(int a[], int &b)
{
	for (int i=0;i<=5;i++)
	{
		a[i]=a[i]*b; 
	}
	
}

int main(){

	int a[5]={1,2,3,4,5}; 
	multiply(a,a[1]); 

	for (int i=0;i<5;i++)
	{
		cout<<a[i]<<"\n";
	}

}
