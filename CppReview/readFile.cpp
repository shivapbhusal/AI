// A program to demonstrate pass by value and pass by reference 
//

#include<iostream>
#include <fstream>
#include<string>
using namespace std; 

int main ()
{
	int y; 
	string x; 
	ifstream inFile;
	inFile.open("myFile.txt"); 
	while (inFile)
	{
	    inFile >> x; 
	    inFile >> y; 
        cout<<x<<endl; 
	}
	inFile.close(); 

}