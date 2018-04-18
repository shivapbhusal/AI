/*
KMeans clustering implementation in C++ 
CS 6200
Shiva Bhusal, Bowling Green State University
*/

#ifndef KMEANS_H 
#define KMEANS_H
#include<iostream> 

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

  double x_value;
  double y_value;  
  Node *next; 
  Node (double x, double y){
  x_value=x;
  y_value=y;  
  next=NULL; 
}
}; 

class LinkedList {
  
  public:
    Node *start; 
    Node *end; 

    LinkedList(){
      start=NULL; 
      end=NULL; 
    }

    void insert(double x, double y)
    {
      Node* n =new Node(x,y); 
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

void display()
    {
      Node *temp=start; 
      std::cout<<"The nodes of the Linked List are: "<<std::endl; 
    while (temp !=NULL)
	 {
	  std::cout<<temp->x_value<<" "<<temp->y_value<<std::endl; 
      temp=temp->next; 
	  }
    }

  }; 

class KMeans {
private:
	int k=0; 
	
public:
	KMeans(int valueOfK){
		k=valueOfK; 
	}

	Coordinate findCenter(LinkedList cluster){
		double total_x=0; 
		double total_y=0;
		int count=0;  
		Node *temp=cluster.start; 
		while (temp !=NULL)
	     {
	  	total_x=total_x+temp->x_value; 
	  	total_y=total_y+temp->y_value; 
    	count=count+1;
    	temp=temp->next;  
	    }
	    total_x=total_x/count; 
	    total_y=total_y/count; 

	    return Coordinate(total_x, total_y); 
	    }

}; 

#endif 