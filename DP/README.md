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

### 5. Edit Distance

Given two strings s and t. Return the minimum number of operations required to convert s to t. </br>
The possible operations are permitted: </br>

Insert a character at any position of the string. </br>
Remove any character from the string. </br>
Replace any character from the string with any other character. </br>
 
Example:

Input: </br>
s = "geek", t = "gesek" </br>
Output: 1 </br>
Explanation: One operation is required </br>
inserting 's' between two 'e's of str1. </br>
- [Edit Distance](https://github.com/pskarthick15/Programming/blob/main/DP/EditDistance.cpp)

### 6. Equal subset sum partition

Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4 </br>
arr = {1, 5, 11, 5} </br>
Output: YES </br>
Explaination: </br>
The two parts are {1, 5, 5} and {11}. </br>
 - [Equal Subset](https://github.com/pskarthick15/Programming/blob/main/DP/equal_subset.cpp)

### 7. Maximum value from Gold mine from all starting points

Given a gold mine of n x m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect. </br>
Examples: </br>
 
Input : mat[][] = {{1, 3, 3}, </br>
                   {2, 1, 4}, </br>
                  {0, 6, 4}}; </br>
                  
Output : 12 </br>
{(1,0)->(2,1)->(1,2)} </br>
- [Gold mine](https://github.com/pskarthick15/Programming/blob/main/DP/max_gold_mine.cpp)

### 8. Maximize The Cut Segments

Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers. </br>
After performing all the cut operations, your total number of cut segments must be maximum. </br>

Example: 

Input: </br>
N = 4 </br>
x = 2, y = 1, z = 1 </br>
Output: 4 </br>
Explanation:Total length is 4, and the cut </br>
lengths are 2, 1 and 1.  We can make </br>
maximum 4 segments each of length 1. </br>
- [Maximum cut](https://github.com/pskarthick15/Programming/blob/main/DP/Max_rod_cut.cpp)

### 9. Longest Common Subsequence 

Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example:

Input: </br>
A = 6, B = 6 </br>
str1 = ABCDGH </br>
str2 = AEDFHR </br>
Output: 3 </br>
Explanation: LCS for input Sequences </br>
“ABCDGH” and “AEDFHR” is “ADH” of </br>
length 3. </br>
- [LCS](https://github.com/pskarthick15/Programming/blob/main/DP/LCS.cpp)

### 10. Longest Increasing Subsequence

Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example:

Input: </br>
N = 16 </br>
A[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15} </br>
Output: 6 </br>
Explanation:Longest increasing subsequence </br>
0 2 6 9 13 15, which has length 6 </br>
- [LIS](https://github.com/pskarthick15/Programming/blob/main/DP/LIS.cpp) </br>


### Largest square formed in a matrix 

Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

Example:

Input: n = 2, m = 2 </br>
mat = {{1, 1}, </br>
       {1, 1}} </br>
Output: 2 </br>
Explaination: The maximum size of the square </br>
sub-matrix is 2. The matrix itself is the </br>
maximum sized sub-matrix in this case. </br>

- An important approach here is that it is not intuitive to use a recursive solution or think in that direction. So just go with the 2D array DP approach. Formula => as all the individual elements in DP of 0th row and column can be a right bottom part of of matrix and form a square matrix of size 1, fill with 1. Then for other elements go with formula dp[i][j]=min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]). </br>
- [Largest Square Matrix](https://github.com/pskarthick15/Programming/blob/main/DP/largest_sq_matrix.cpp)

### Minimum cost to fill given weight in a bag

Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1 </br>

Note: </br>
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable </br>
2. It may be assumed that there is infinite supply of all available packet types. </br>

Example:

Input: N = 5, arr[] = {20, 10, 4, 50, 100} </br>
W = 5 </br>
Output: 14 </br>
Explanation: choose two oranges to minimize </br>
cost. First orange of 2Kg and cost 10. </br>
Second orange of 3Kg and cost 4. </br>
- [Min Cost to fill weight in bag](https://github.com/pskarthick15/Programming/blob/main/DP/fill_weight_in_bag.cpp)

### Minimum removals from array to make max – min <= K

Given N integers and K, find the minimum number of elements that should be removed, such that Amax-Amin<=K. After the removal of elements, Amax and Amin is considered among the remaining elements. 

Examples: 

Input : a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20} </br>
          k = 4 </br>
Output : 5 </br>
Explanation: Remove 1, 3, 4 from beginning </br>
and 17, 20 from the end. </br>

Input : a[] = {1, 5, 6, 2, 8}  K=2 </br>
Output : 3 </br>
Explanation: There are multiple ways to </br>
remove elements in this case. </br>
One among them is to remove 5, 6, 8. </br>
The other is to remove 1, 2, 5 </br>
- [Minimum elements to remove to make <=K](https://github.com/pskarthick15/Programming/blob/main/DP/min_elements%20to_remove.cpp)

### Knapsack with Duplicate Items

Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Example:

Input: N = 2, W = 3 </br>
val[] = {1, 1} </br>
wt[] = {2, 1} </br>
Output: 3 </br>
Explanation: </br>
1.Pick the 2nd element thrice. </br>
2.Total profit = 1 + 1 + 1 = 3. Also the total </br>
  weight = 1 + 1 + 1  = 3 which is <= W. </br>

- [Knapsack duplicate](https://github.com/pskarthick15/Programming/blob/main/DP/knapsack_duplicate.cpp)

### Word Break (Also in tries. This is not the optimal solution)

Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

Note: From the dictionary B each word can be taken any number of times and in any order.

Example 1: </br>
Input: </br>
n = 12 </br>
B={"i","like","sam","sung","samsung","mobile","ice","cream","icecream","man", "go", "mango" } </br>
A = "ilike" </br>
Output: </br>
1 </br>
Explanation: </br>
The string can be segmented as "i like". </br>
Example 2: </br>
Input: </br>
n = 12 </br>
B={"i","like","sam","sung","samsung","mobile","ice","cream","icecream","man", "go", "mango" } </br>
A = "ilikesamsung" </br>
Output: </br>
1 </br>
Explanation: </br>
The string can be segmented as </br>
"i like samsung" or "i like sam sung". </br>
- [Word Break](https://github.com/pskarthick15/Programming/blob/main/DP/word_break.cpp)

### Coin game winner where every player has three choices

A and B are playing a game. At the beginning there are n coins. Given two more numbers x and y. In each move a player can pick x or y or 1 coins. A always starts the game. The player who picks the last coin wins the game or the person who is not able to pick any coin loses the game. For a given value of n, find whether A will win the game or not if both are playing optimally.

Examples: 

Input :  n = 5, x = 3, y = 4 </br>
Output : A </br>
There are 5 coins, every player can pick 1 or </br>
3 or 4 coins on his/her turn. </br>
A can win by picking 3 coins in first chance. </br>
Now 2 coins will be left so B will pick one </br>
coin and now A can win by picking the last coin. </br>
- [Coin Game](https://github.com/pskarthick15/Programming/blob/main/DP/coin_game.cpp)

### Buy and Sell a Share at most twice

In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Buy->sell->Buy->sell). The stock prices throughout the day  are represented in the form of an array price. 

Given an array price of size N, find out the maximum profit that a share trader could have made.

Example 1:

Input: </br>
6 </br>
10 22 5 75 65 80 </br>
Output: </br>
87 </br>
Explanation: </br>
Trader earns 87 as sum of 12, 75 </br>
Buy at 10, sell at 22, </br>
Buy at 5 and sell at 80 </br>
Example 2: </br>

Input: </br>
7 </br>
2 30 15 10 8 25 80 </br>
Output: </br>
100 </br>
Explanation: </br>

Trader earns 100 as sum of 28 and 72 </br>
Buy at price 2, sell at 30, </br>
Buy at 8 and sell at 80 </br>
- [Buy Sell Stocks](https://github.com/pskarthick15/Programming/blob/main/DP/Buy_sell_stocks.cpp)

### Wildcard Pattern Matching

Given a text and a wildcard pattern, implement wildcard pattern matching algorithm that finds if wildcard pattern is matched with text. The matching should cover the entire text (not partial text).
The wildcard pattern can include the characters ‘?’ and ‘*’ 
‘?’ – matches any single character 
‘*’ – Matches any sequence of characters (including the empty sequence)

For example,

Text = "baaabab" </br>

Pattern =*ba*ab", output : true </br>
Pattern = "baaa?ab", output : true </br>
Pattern = "ba*a?", output : true </br>
Pattern = "a*ab", output : false </br>
