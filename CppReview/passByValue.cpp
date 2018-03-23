// A program to demonstrate pass by value and pass by reference 
//

#include<iostream>
using namespace std; 

void swapByValue(int a, int b)
{
	int temp=a; 
	a=b; 
	b=temp; 
}

void swapByRef(int &a, int &b)
{
	int temp=a; 
	a=b; 
	b=temp; 
}

int main()
{
	int a=10; 
	int b=20;

        cout<<"The value before swap: "<<"a: "<<a<<"b: "<<b<<"\n"; 
        swapByValue(a,b); 
        cout<<"The value after swap: "<<"a: "<<a<<"b: "<<b<<"\n";

        cout<<"The value before swap: "<<"a: "<<a<<"b: "<<b<<"\n"; 
        swapByRef(a, b); 
        cout<<"The value after swap: "<<"a: "<<a<<"b: "<<b<<"\n";	

}
