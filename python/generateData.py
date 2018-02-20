'''
Three class Perceptron implementation 
Author: Shiva Bhusal
Bowling Green State University

'''
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np

def generateDatset(x,y,z):
    dataList=[]
    i=0.5
    while (i<=2):
        dataList.append([x+i,y,z])
        dataList.append([x-i,y,z])
        i=i+0.5

    j=0.5
    while (j<=2):
        dataList.append([x,y+j,z])
        dataList.append([x,y-j,z])
        j=j+0.5

    k=0.5
    while (k<=2):
        dataList.append([x,y,z+k])
        dataList.append([x,y,z-k])
        k=k+0.5
    
    return dataList

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

centers=[[0,0,0],[5,5,5],[-5,-5,-5]]

for x,y,z in centers:
    ax.scatter(x,y,z,c='r')

for x,y,z in [[0,0,0],[-5,-5,-5],[5,5,5]]:
    dataList=generateDatset(x,y,z)
    for x_o,y_o,z_o in dataList:
         ax.scatter(x_o,y_o,z_o,c='b')

ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

plt.show()