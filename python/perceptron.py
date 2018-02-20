from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

XA=[0,0,0,1,0]
YA=[0,1,2,3,4]
ZA=[0,0,0,0,0]

XB=[7,7,7,7,7]
YB=[0,1,2,3,3.5]
ZB=[0,0,0,0,0]


ax.scatter(XA,YA,ZA,c='r')
ax.scatter(XB,YB,ZB,c='b')

ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

plt.show()

def calculateOutput(theta,weights, x,y,z):
    result=x*weights[0]+y*weights[1]+z*weights[2]+weights[3]
    if (result>theta):
    	return 1
    else:
    	return 0 
    

THETA=0.1
LEARNING_RATE=0.5
MAX_ITER=7

X=[0,0,0,1,7,7,7,7]
Y=[0,1,2,3,0,1,2,3]
Z=[0,0,0,0,0,0,0,0]


weights=[0,0,0,0] 
outputs=[1,1,1,1,-1,-1,-1,-1]
globalError=10
iteration=0

while iteration<=MAX_ITER:
    for i in range(len(X)-1):
        output=calculateOutput(THETA,weights,float(X[i]),float(Y[i]),float(Z[i]))
        Error=float(outputs[i])-output
        weights[0]=float(weights[0])+LEARNING_RATE*Error*X[i]
        weights[1]=float(weights[1])+LEARNING_RATE*Error*Y[i]
        weights[2]=float(weights[2])+LEARNING_RATE*Error*Z[i]
        weights[3]=float(weights[2])+LEARNING_RATE*Error
        
    iteration=iteration+1

print(weights)    

print(calculateOutput(THETA,weights,0,4,0))
print(calculateOutput(THETA, weights,7,3.5,0))