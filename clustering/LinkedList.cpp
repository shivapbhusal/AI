/*
Doubly Linked List Implementation. 
Adapted from Programming Exercise -01 
Course: CS6200 
Submitted By Shiva Bhusal
Bowling Green State University 
*/


#include<iostream>
#include<fstream>
#include<string>

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
      }
  }

void deleteEnd()
  {
    end->next=NULL; 

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


int main()
{
  LinkedList *L=new LinkedList();
  for (int i=0;i<=10;i++)
  {
    L->insert(i,i+1); 
  }

  L->display();
  std::cout<<std::endl; 

}
