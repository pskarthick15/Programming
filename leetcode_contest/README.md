
## Question 1 </br>
Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

- For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node. </br>
- (reverse_odd_levels)[https://github.com/pskarthick15/Programming/blob/main/leetcode_contest/contest_1_q2.cpp]

## Question 2 </br>
You are given an array words of size n consisting of non-empty strings.

We define the score of a string word as the number of strings words[i] such that word is a prefix of words[i].

For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

Note that a string is considered as a prefix of itself. </br>
(prefix_scores_in_array_of_strings)[https://github.com/pskarthick15/Programming/blob/main/leetcode_contest/contest_1_q2.cpp]
