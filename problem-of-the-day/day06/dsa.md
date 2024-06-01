## DSA Problem of the Day (01/06/2024)

### Linear Data Structures

Today we wrap up all the linear data structures (stack,queue,linked list) and related topics before we begin with no linear (trees/graphs) from tommorow. Todays problem set will try to cover broad range of topics/ideas.

1. [Intersection of linked list](https://leetcode.com/problems/intersection-of-two-linked-lists/description/?envType=problem-list-v2&envId=mvdlzc9e):- $O(1)$ Space Complexity. Compare this with [Single Number I](https://leetcode.com/problems/single-number/description/) and [Single Number II](https://leetcode.com/problems/single-number-ii/description/).
2. [Maximum SubArray Sum](https://leetcode.com/problems/maximum-subarray/description/?envType=problem-list-v2&envId=mvdlzc9e):- $O(n)$ Time Complexity. $O(n^2)$ is also decent. For $O(n^2)$ read about prefix sum.
   Say $f$ is a function with signature $\text{int} -> \text{int} -> \text{int}$, ie which which takes in 2 integer and returns 1. $f$ also has an identity element say $e$, such that for all $x$,  $f(e,x) = x$.
   Now similar to subarray sum from $a_l$ to $a_r$ in an array $a$, we can define $F$ as $F(l,r) = f(a_l,F(l+1,r))$ and $F(l,l) = a_l$.  For example if the operation $f$ is AND operation, then $ F(1,3) = a_1 \text{ AND } a_2 \text{ AND } a_3 $.
   Now with the definitions clear. The question is, what conditions must $f$ satisfy so that $F(l,r)$ be calculated using the strategy of prefix sum ? Explicity
   $ F(l,r) = g(F(0,r),F(0,l-1))$ for some function $g$ ?? Compare $f$ with a [monoid](https://en.wikipedia.org/wiki/Monoid#:~:text=In%20other%20words%2C%20a%20monoid,ary%20(or%20nullary)%20operation.).
   Can you think of some example functions which satisfy this ? XOR, +  are few examples. These conditions allow us to answer any range query in O(1) time. What if we drop one condition ?
   How does this affect our capability to answer range queries ?
3. [Linked List Cycle I](https://leetcode.com/problems/linked-list-cycle-ii/?envType=problem-list-v2&envId=mvdlzc9e):- In O(1) Space. What is the time complexity if there are in total $n$ nodes in the list.
   Let us discuss a variation of fast slow technique, instead of moving the fact pointer by 2 moves, we move it by $k$ moves each time.Say there are $a,b$ nodes in the linear part and cycle part of the linked list respectively. And we reach our conclusion in $m$ moves, then $( mk-a \equiv m - a  (\text{ mod} \text{ b}))$. Thus our condition becomes $b$ must divide $m(k-1)$ and $ m>a $. So time complexity is $O(m+a)$, $m$ depends on $k$. Take it forward from here. Interested users might see [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/description/?envType=problem-list-v2&envId=mvdlzc9e).
4. [Kevin&#39;s Permuations](https://codeforces.com/contest/1754/problem/B):- Simple Implementation Problem.
5. [Torus Problem](https://codeforces.com/contest/1765/problem/K):- Simple Implementation Problem.
