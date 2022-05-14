## Dynamic Programming

### 1. Coin Change problem

Given denomination of coins find the min no of ways needed to achieve a given amount from those denominations</br>
ex: [1,2,5] </br>
amount=11(say)</br>
now best is 3 (i.e 5,5,1)</br>

### 2. Knapsack problem

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.</br>

In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example: </br>

Input: </br>
N = 3 </br>
W = 4 </br>
values[] = {1,2,3} </br>
weight[] = {4,5,1} </br>
Output: 3 </br>

### 3. nCr or factorial problem

Given two integers n and r, find nCr. Since the answer may be very large. </br>

Example 1: </br>
Input: n = 3, r = 2 </br>
Output: 3 </br>
Explaination: 3C2 = 3. </br>
