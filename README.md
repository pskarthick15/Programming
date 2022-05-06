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
- [Longest prefix word](https://github.com/pskarthick15/Programming/blob/main/optimal_game.cpp)
