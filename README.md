# Important advanced Prgramming problems

### 1. Optimal Game
Problem stnt: Given an array and 2 players(yourself and another), Assuming that you start the game and the game goes with the rule that the player given chance can 
either choose the 1st or the last element in the array, find the max value that the player who starts 1st can get.
ex: [5,3,7,10] -> here 1st player - 5, 2nd player - 3, 1st player -7 , 2nd player - 10. So 1st player gets 5+7=12. But, another best case possible is:
1st player - 10, 2nd player - 7, 1st player - 15, 2nd player - 3. So here 1st player gets 15 which is max possible scenario. 
Note: Assume that the opponent is as clever and intelligent as you.
Soln idea: Always remember in game related problems we try to maximize our value in our turn and opponent tries to minimize our score when he plays. Use DP as all scenarios of greedy(Naive approach) dont work.

- [Optimal game](https://github.com/pskarthick15/Programming/blob/main/optimal_game.cpp)

### 2. Trie insertion, startswith and search functionality and understanding its basic structure
- [trie insert startswith search](https://github.com/pskarthick15/Programming/blob/main/optimal_game.cpp)

### 3. Given a series or array of strings find the longest word in the string that has all the prefix words in the same array.
For ex: given array => ["n","ni","nin","ninj","ninja","ninga"], here ninja is the longest word with all its prefixes of n, ni, nin, ninj and ninja in the same array itself.
- [Longest prefix word](https://github.com/pskarthick15/Programming/blob/main/longest_word.cpp)

### 4. No of distinct substrings in a given string

Given a string for ex. say abab find the number of distinct substrings in it. In this case it is[a,ab,aba,abab,b,ba,bab] and a general phi or null string. So 8.
- [Distinct substrings](https://github.com/pskarthick15/Programming/blob/main/trie_4.cpp)


### 5. Maximum xor value between 2 given array values

Given 2 arrays arr1 and arr2 find the max value of xor possible between those 2 arrays. Now let us take a minified version of given problem. Let us say given an array arr and a number x, we want to find the max value for arr[i]^x. Now suppose we have the bit representation 0110. Now max exor is occurred when it is 1001. That is in places where 0 in number 1 needed and in places of 1 in number 0 is needed right. So, the question boils down to:
ex: arr => [9,8,7,5,4] 9=>01001 , 8=>01000, 7=>00111, 5=>00101. say we have x=8 or =>01000. So now we need a 1 in 1st position. 9=>eliminate and 8=>eliminate and so on till all. So no other go keep 0 only and do or with 0 and move to next bit. Now we need a 0 in 2nd position. So, straight away 9 and 8 eliminate so ans is 7 or 5. So now 2nd palce is 1. So or it in our solution. So keep eliminating like this till we reach the result.
- [Max xor](https://github.com/pskarthick15/Programming/blob/main/trie_5.cpp)

### 6. Based on offline queries the approach for exoring is same.

Given arr [0,1,2,3,4] and q queries say q=2. so 1 3 and 5 6. where 1 is xi and 3 is ai. We need to return the max xor of xi with arr[i] such that i<=ai.
The algo is:
1st sort the given array in ascending order.
Then do offline queriying which is nothing but store index of query for later use in a DS and then sort based on ai. Then see algo in notebook

- [Offline query](https://github.com/pskarthick15/Programming/blob/main/trie_6.cpp)

### 7. Shortest unique prefix to represent each word uniquely
Given a list of strings, we need to find the shortest prefix of string such that it can be uniquely identified among the list of strings.
=>ex: i/p: [zebra,dog,duck,dove], o/p: [z,dog,du,dov]
- [Shortest prefix](https://github.com/pskarthick15/Programming/blob/main/trie_sde1.cpp)
