## Dynamic Programming

### 1. Coin Change problem

Given denomination of coins find the min no of ways needed to achieve a given amount from those denominations</br>
ex: [1,2,5] </br>
amount=11(say)</br>
now best is 3 (i.e 5,5,1)</br>

- [Coin Change](https://github.com/pskarthick15/Programming/blob/main/DP/coin_change.cpp)
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

- [Knapsack](https://github.com/pskarthick15/Programming/blob/main/DP/knapsack.cpp)

### 3. nCr or factorial problem

Given two integers n and r, find nCr. Since the answer may be very large. </br>

Example 1: </br>
Input: n = 3, r = 2 </br>
Output: 3 </br>
Explaination: 3C2 = 3. </br>

- [nCr](https://github.com/pskarthick15/Programming/blob/main/DP/nCr.cpp)

### 4. Matrix Chain Multiplication (Partition DP)

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have: 

(ABC)D = (AB)(CD) = A(BCD) = ....

However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then, </br>

(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations </br>
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations. </br>
Clearly the first parenthesization requires less number of operations. </br>
Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i]. We need to write a function MatrixChainOrder() that should return the minimum number of multiplications needed to multiply the chain. 

Input: p[] = {40, 20, 30, 10, 30} </br>
Output: 26000 </br>
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30. </br>
Let the input 4 matrices be A, B, C and D.  The minimum number of </br>
multiplications are obtained by putting parenthesis in following way </br>
(A(BC))D --> 20 * 30 * 10 + 40 * 20 * 10 + 40 * 10 * 30 </br>

- [MCM](https://github.com/pskarthick15/Programming/blob/main/DP/mcm.cpp)
