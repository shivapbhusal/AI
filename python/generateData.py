'''
Three class Perceptron implementation 
Author: Shiva Bhusal
Bowling Green State University

'''
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

centers=[[0,0,0],[5,5,5],[-5,-5,-5]]


for x,y,z in centers:
    ax.scatter(x,y,z,c='r')

ax.scatter(0,0,0.5,c='b')
ax.scatter(0,0,1,c='b')
ax.scatter(0,0,1.5,c='b')
ax.scatter(0,0,2,c='b')

ax.scatter(0.5,0,0,c='b')
ax.scatter(1,0,0,c='b')
ax.scatter(1.5,0,0,c='b')
ax.scatter(2,0,0,c='b')

ax.scatter(0,0.5,0,c='b')
ax.scatter(0,1,c='b')
ax.scatter(0,1.5,0,c='b')
ax.scatter(0,2,0,c='b')

ax.scatter(0,0,-0.5,c='b')
ax.scatter(0,0,-1,c='b')
ax.scatter(0,0,-1.5,c='b')
ax.scatter(0,0,-2,c='b')

ax.scatter(-0.5,0,0,c='b')
ax.scatter(-1,0,0,c='b')
ax.scatter(-1.5,0,0,c='b')
ax.scatter(-2,0,0,c='b')

ax.scatter(0,-0.5,0,c='b')
ax.scatter(0,-1,c='b')
ax.scatter(0,-1.5,0,c='b')
ax.scatter(0,-2,0,c='b')




ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

plt.show()