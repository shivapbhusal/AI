/*
KMeans clustering implementation in C++ 
CS 6200
Shiva Bhusal, Bowling Green State University
*/

#ifndef KMEANS_H 
#define KMEANS_H
#include<iostream> 
#include<math.h>

struct Coordinate{
	double x_value; 
	double y_value; 

	Coordinate(double x, double y)
	{
		x_value=x; 
		y_value=y; 
	}
}; 

struct Node
{
  Coordinate *c; 
  Node *next; 
  Node (double x, double y){
  x_value=x;
  y_value=y;  
  next=NULL; 
}
}; 

class LinkedList {
private:

public:
	Node *start; 
    Node *end; 

    LinkedList(){
      start=NULL; 
      end=NULL; 
    }

    void insert(double x, double y)
    {
      Node *n =new Node(x,y); 
      if (start==NULL){
	    start=n;
	    end=n;  
      }

      else {
	     end->next=n; 
       end=n;  
       end->next=NULL; 
      }
  }

  void delete()
  {

  }
 
}; 

#endif 