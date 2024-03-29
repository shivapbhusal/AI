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

  double x_value;
  double y_value;  
  Node *next; 
  Node (double x, double y){
  x_value=x;
  y_value=y;  
  next=NULL; 
}
}; 

struct ClustersStructure
{
  Coordinate center; 
  LinkedList clusterPoints; 
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

	double findDistance(Coordinate c1, Coordinate c2)
	{
		double x=c1.x_value; 
		double y=c2.y_value; 

		double distance=sqrt(pow((x-c1.x_value),2)+pow((y-c2.y_value),2));
		return distance;  
	}

	int getNearestCluster(Coordinate c, LinkedList centers)
	{
		double minDist=findDistance(c, centers.start)
		int clusterIndex=0; 
		Node current=centers.start; 
		while (current!=NULL)
		{
			tempDist=findDistance(c, (current.x, current.y))
			if (tempDist<minDist)
			{
				clusterIndex=clusterIndex+1
			}
			current=current.next; 
		}
		return clusterIndex; 
	} 

	LinkedList runAlgorithm(LinkedList dataSet)
	{
		LinkedList clusters[k]; 
		Coordinates clusterCenters[k];

		current=dataSet.start;
		i=0; 
		while(i<k)
		{
			current=current.next; 
			clusterCenters[i]=new Coordinates(current.x_value, current.y_value)
		    i=i+1;  
		}
		LinkedList newClusters[k]; 
		
		while (!checkClusters(clusters, newClusters))
		{
			current=dataSet.start;
		i=0; 
		while(current!=NULL)
		{
			getNearestCluster(new Coordinates(current.x_value, current.y_value), clusterCenters)
			

		}

	}



			newCenters=[]
        for c in centers:
            newCenters.append(c)
        count=count+1
        for point in data:
            j=getNearestCluster(point, centers)
            clusters[j].append(point)

        for i in range(len(clusters)):
centers[i]=findCenter(clusters[i])

		}
	} 

	Boolean checkClusters(Coordinates c1, Coordinates c2)
	{
		return 0
	}
}; 

#endif 