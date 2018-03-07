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
b1=0.5 
b2=0.5

'''
We assume, we have two inputs, a hidden layer with two nodes, and a output Node. 
So, hidden layer will have 4 weights whereas output layer will have two weights. 

'''
W=[[0.5,0.2,0.8,0.1],[0.5,0.5]]
N1=Node()
N1.calculateOutput(10)
N2=Node()
N3=Node()

# Step 1

inputN1=W[0][0]*inputs[0]+W[0][1]*inputs[1]
N1.calculateOutput(inputN1)

inputN2=W[0][2]*inputs[0]+W[0][3]*inputs[1]
N2.calculateOutput(inputN2)

inputN3=N1.getOutput()*W[1][0]+N2.getOutput()*W[1][1]
N3.calculateOutput(inputN3)

# Check the output of Step 1
print(N3.getOutput())
        



