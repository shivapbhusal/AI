'''
Python Implementation of BackPropagation Algorithm 
Author: Shiva Bhusal, BGSU 
'''
import math as math

class Node():
    '''
    A Node class
    Has Input and the corresponding output function. 
    '''
    def __init(self):
        self.output=0
        self.w1=0
        self.w2=0

    def calculateOutput(self,inputValue):
        self.output=(1/(1+math.pow(math.e,inputValue)))

    def getOutput(self):
        return self.output

    def updateW1(self,newValue):
        self.w1=newValue
    
    def updateW2(self,newValue):
        self.W2=newValue 


inputs=[1,2]
outputs=[1]

'''
We assume, we have two inputs, a hidden layer with two nodes, and a output Node. 
So, hidden layer will have 4 weights whereas output layer will have two weights. 

'''
weightList=[[0.5,0.2,0.8,0.1],[0.5,0.5]]
N1=Node()
N1.calculateOutput(10)
N2=Node()
N3=Node()

for layers in weightList:
    for weights in layers:
        print(weights)



