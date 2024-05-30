# DSA Problem of the Day (29/05/2024)

## Sorting/Searching and Binary Search

Today, we will continue solving some problems on binary search. And learn about sorting and searching. Before that few follow ups on binary search.
The core idea of binary search relies on dividing our search space by 2. Which eventually leads to a logarithmic complexity. What if we divide our search space into 3 parts (or just say n), which will lead to a faster convergence to solution. Why it isn't used in real life?

To begin, follow [LeetCode](https://leetcode.com/) and [CSES](https://cses.fi/problemset/list/) to solve the following problems. They will help you understand and practice key concepts in sorting:

1. [Search in rotated array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/):- Binary Search Problem.
2. [Distinct Numbers](https://cses.fi/problemset/task/1621):- Maps(ordered/unordered) leads to a O(n) solution too. Whereas sorting gives O(nlogn). What is the tradeoff between them ?
3. [Ferris Wheel](https://cses.fi/problemset/task/1090).

## Resources

1. [Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)
2. [Stable Sorting](https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/)

## FollowUps

* Can a sorting algorithm which only uses < or > operations (>= or <=),  sort faster than O(nlogn) ?
* What is a stable sorting ? Can any sorting algorithm be made stable ? If yes then what is the use of fussing over stability ? If no, then why ?
* Can a sorting algorithm sort in place, does at max n swaps and be O(nlogn) in time complexity ?

We'll cover more topics in DSA in the following weeks, so it is recommended you try to complete these problems as soon as possible.

**Note:** Solutions to [day02](../day02) are uploaded.

## Solutions
1. Search in rotated array :- [C++](./33%20Search%20in%20Rotated%20Array.cpp), [Python3](./33%20Search%20in%20Rotated%20Array.py)
2. Distinct Numbers :- [C++](./1090%20Ferris%20Wheel.cpp), [Python3](./1621%20Distinct%20Number.py)
3. Ferris Wheel :- [C++](./1090%20Ferris%20Wheel.cpp), [Python3](./1090%20Ferris%20Wheel.py)