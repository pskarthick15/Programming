## 1. BFS Variant-1
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2 </br>
Output: [[2,2,2],[2,2,0],[2,0,1]] </br>
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel. </br>
- [bfs variant 1](https://github.com/pskarthick15/Programming/blob/main/graphs/bfs_variant1.cpp) 


## BFS variation 2

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]] </br>
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3. </br>


Example 2:
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]] </br>
Output: 2 </br>


Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]] </br>
Output: -1 </br>
Explanation: There are not enough cables. </br>

- [BFS variant 2](https://github.com/pskarthick15/Programming/blob/main/graphs/bfs_var2.cpp)

## BFS Variant-3

Given an input having a 2D array where 0s represent water and 1s represent land, find the no of Islands present in the grid. Assume only 0s and 1s are present in the 2D matrix.

EXMAPLE 1 </br>
INPUT: </br>
4 2 </br>

0 1 </br>
1 0 </br>
1 1 </br>
1 0 </br>

OUTPUT: 1
As the no of Islands(which is land area covered by water) is 1 in the grid above

EXAMPLE 2 </br>
INPUT: </br>
5 4

0 1 1 0 </br>
0 1 1 0 </br>
0 0 1 0 </br>
0 0 0 0 </br>
1 1 0 1 </br>

OUTPUT: 3
As the no of Islands(which is land area covered by water) is 3 in the grid above

- [BFS-Variant 3](https://github.com/pskarthick15/Programming/blob/main/graphs/island.cpp)


## DFS Variant-1

Given a matrix n*m, a source and destination and a colour, Colour the matrix such that all the 4 connected components starting from sr,sc are coloured with the new colour. That is colour the 4 connected neighbours of sr,sc with newcolour then check for their neighbours and colour them also and so on 

Example 1: 

Input: </br>
1 1 1 </br>
1 1 0 </br>
1 0 1 </br>
sr=1, sc=1 </br>
necolour=2 </br>

Output: </br>
2 2 2 </br>
2 2 0 </br>
2 0 1 </br>
As here, we have the input start with 1,1 now the oldcolour of it is 1 so we check the neighbours if they are also of the same colour which is 1, if yes colour them then check their neighbours and so on till we colour all.

- [Floodfill Algorithm](https://github.com/pskarthick15/Programming/blob/main/graphs/Floodfill_dfs.cpp)


## BFS Variant-3 

 Given a binary grid of N*M. Find the distance of the nearest 1 in the grid for each cell.

The distance is calculated as |i1  – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.

Example:</br>

Input:</br>
1 0 1</br>
1 1 0</br>
1 0 0</br>

Output:</br>
0 1 0</br>
0 0 1</br>
0 1 2</br>

Breadth First Search, BFS, is a traversal technique where we visit the nodes level-wise, i.e., it visits the same level nodes simultaneously, and then moves to the next level. 

The intuition is that BFS will take a step from cells containing 1 and will reach out to all zeros that are at a distance of one. Apparently, we can say that the nearest 1 to the 0s is at a distance of one. Again if we take another step, we will reach the next set of zeros, for these zeros 1 is at a distance of two. If we continue the same, till we can go, we can reach all the 0’s possible. 

We will choose the BFS algorithm as it moves step by step and we want all of them to traverse in a single step together so that we can have a minimum count with us.

- [Nearest1s](https://github.com/pskarthick15/Programming/blob/main/graphs/nearest1ofele.cpp)

## DFS Variant-2

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example: 
Input: grid = [ </br>
  ["1","1","1","1","0"], </br>
  ["1","1","0","1","0"], </br>
  ["1","1","0","0","0"], </br>
  ["0","0","0","0","0"] </br>
] </br>

Output: 1 (No. of connected 1s component is 1 only)

Example 2:
Input: grid = [ </br>
  ["1","1","0","0","0"], </br>
  ["1","1","0","0","0"], </br>
  ["0","0","1","0","0"], </br>
  ["0","0","0","1","1"] </br>
] </br>
Output: 3

## BFS Variant-4

Problem Statement: You are given an N x M binary matrix grid, where 0 represents a sea cell and 1 represents a land cell. A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid. Find the number of land cells in the grid for which we cannot walk off the boundary of the grid in any number of moves.


ex:</br>
![image](https://user-images.githubusercontent.com/53825361/209572539-8eba3bc8-d699-42eb-8951-16fb539ff187.png) </br>
Output: 3</br>
[No of enclaves](https://github.com/pskarthick15/Programming/blob/main/graphs/noofenclaves.cpp)

