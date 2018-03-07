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

    def calculateOutput(self,inputValue):
        self.output=(1/(1+math.pow(math.e,inputValue)))

    def getOutput(self):
        return self.output

inputs=[1,2]
outputs=[1]

weights=[0.5,0.4,0.1,0,0.9,0.1]
N1=Node()
N1.calculateOutput(10)
N2=Node()
N3=Node()
print(N1.output)
