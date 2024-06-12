# DSA Problem of the Day (13/06/2024)

## Range Queries I

We begin solving range queries problems. This will lead to introduction to few more data structures. Before that we discuss some topics. It will also answer the follows ups from day06 [dsa](../day06/dsa.md) problem number 2.

### Understanding Range Queries

We begin by understanding what is a range query. Suppose given a array of integers, what is the sum/product/xor etc of the numbers from index $l$ to $r$ ? Suppose the array size is $n$ and there are $q$ queries, naive implementation gives $O(nq)$ time complexity. Using some data structures/techniques we can often improve this to $O(n+q)$ or $O(n+qlog(n))$ etc. But as you must know by now, to improve the time complexity, we must do some "PreComputation". But what does precomputation mean ? As instructed in [day06 dsa](../day06/dsa.md) to learn about prefix sum. The step of computing the prefix sum (or in general any "information" on some part of the array) is called "Precomputation". We encourage readers to revist [prefix sum](https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/) is not already covered.

### Segment Tree

Now we begin with the easiest but not linear data structure of range queries. Read the following article only till the section Memory Efficient Implementation, ie (before Advanced versions of Segment Trees, we will cover the later today only) [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html).

## Crux of the matter

Now the following discussion will motivate students to come up with more data structures for range queries by themselves and think of them as a natural extension of common sense (like Fenwick Tree, Sparse Table etc).

### Notations

We call a multiset of numbers as "group of numbers". So {1,1,3,2,3} is a valid multiset. These group of numbers follow same properties of union and intersection, and order do not matter.
ie {1,2} ∪  {1,3} = {1,1,3} and {1,1,2} ∩ {1,3} = {1} and {1,2} - {1,3} = {2}. Say a function $f$ with 2 input when applied on a group of numbers succesively(call this $F(A)$, where $A$ is the group), the order of number do not matter, eq (sum/product/min/max/xor/or/and of group of number), we only focus on these kinds of function ([1]()).

### Propery 1

Say A and B are 2 group of numbers, and we know $F(A)$ and $F(B)$, the question is can we find $F(A-B)$ only using the information $F(A)$ and $F(B)$ and not knowing individual elements of $A,B$, answer this for (sum/product/min/max/xor/or/and).

If the answer is YES, we can then we solve every single range query in $O(1)$ with $O(n)$ precomputation. How ? Using a similar technique as prefix sum as told above.

### Propery 2

But what if the answer is NO (as in the case with min/max/and/or) ?? Can we do anything ? Sometimes yes. Say we know $F(A)$ and $F(B)$, can we compute $F(A+B)$ only using the information $F(A)$ and $F(B)$ and not knowing individual elements of $A,B$ ?

If the answer is YES, (which obvious from ([1]())), then we can answer our query in $O(logn)$. But How ? We divide our array into smaller parts(kinda binary search) and compute the $f$ on these small parts. And while answering our query, we find smaller parts which when combined make the part asked in query, and we are done.

But what is different in what I just told, and what u guys read in segment tree article ?
No where in the discussion did I mention that elements on which precomputation is performed need to contitnous. In segment tree we divide it the array in continuos almost equal chunks. What if we divide the array indices based on binary representation. Like indices with $i^{th}$ bit 0 and 1 form 2 groups for different $i's$
**Note:** One more different technique is using sparse table to answer static range minimum queries. Do check out.

### Left Over

The ways an array is divided into smaller parts can be broadly categorized into 2 types. one where 2 distinct parts never overlap (like segment tree, precomputation time complexity $O(n)$), or where they might overlap (sparse table, generaly time complexity of precomputation $O(nlogn)$).
The 2 properties mentioned above are the answer to the properties asked in the follow up question from day06.

## Resources

1. [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)
2. [Fenwick Tree](https://cp-algorithms.com/data_structures/fenwick.html)
3. [Sqrt Decomposition](https://cp-algorithms.com/data_structures/sqrt_decomposition.html)
4. [Sparse Table](https://cp-algorithms.com/data_structures/sparse-table.html)

Compare the time complexity of precomputation and answering queries for each of the above.

**Note:** All the above techniques/data structure are quite similar and knowing only 1 is generally enough to solve most range queries technique.

## Problems

1. [Static Range Sum Queries](https://cses.fi/problemset/task/1646) and [Range Xor Queries](https://cses.fi/problemset/task/1650)
2. [Static Range Minimum Queries](https://cses.fi/problemset/task/1647)
3. [Dynamic Range Sum Queries](https://cses.fi/problemset/task/1648)
4. [Dynamic Range Minimum Queries](https://cses.fi/problemset/task/1649)
5. [Forest Queries](https://cses.fi/problemset/task/1652)

**Note:** Solution to [day15](../day15) have been uploaded
