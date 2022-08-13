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

- [Floodfill_Algorithm](https://github.com/pskarthick15/Programming/blob/main/graphs/Floodfill_dfs.cpp)



