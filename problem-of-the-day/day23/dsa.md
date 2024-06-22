# DSA Problem of the Day (19/06/2024)

## Binary Search On Answer
Today we will learn about Binary Search on Answer which is a problem solving technique important for coding rounds.

### Main Idea
This algorithm generally works on problems that ask to find the maximum or minimum value of some x(which lies in the range from LOW to HIGH) for which the Predicate function is true. The answer for any x in the search space ([LOW, HIGH]) is decided whether true or false by a function called the Predicate function. It is a boolean function. It returns true if the answer for that x is true and false otherwise. The role of this function is to guide the binary search process by indicating which half of the current search space contains the solution. 

A predicate function would look something like this

![image](https://media.geeksforgeeks.org/wp-content/uploads/20220202111849/Screenshot20220202111814.jpg)

As can be observed, in a monotonic predicate function, the value can change from true to false or vice versa, a maximum of one time. 

### Why are we able to apply the binary search on the answer?
Binary search is mainly applied to monotonic sequences, where the values consistently increase or decrease. To use binary search on the answer, we need a sequence that exhibits monotonic behavior. This is where the Predicate function comes in.

The Predicate function generates a boolean value for each element in the search space. If we map true to 1 and false to 0, the sequence of boolean values becomes a monotonic sequence. This transformation allows us to apply binary search effectively.

For example, if f(x) is given by the following function:

f(1) = true
f(2) = true
f(3) = true
f(4) = true
f(5) = false
f(6) = false
f(7) = false

This sequence, when interpreted as 1 for true and 0 for false, is:

1,1,1,1,0,0,0

This sequence is clearly monotonic (non-increasing). To find the maximum value for which the Predicate function is true, we need to identify the last occurrence of true. Binary search can efficiently find this point.

### Let’s understand this via an example.

[Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/description/) - Have a look at this question

### How to identify Binary Search on answer:
Whenever we are able to identify that the answer of the problem lies between in a range L to R and there is a Monotonic Behaviour of answer in range L to R then we can think to apply binary search on answer.

### Finding out the Monotonic Relation 
We can define the predicate function to take a k and return true if koko can complete the pile with that k and false otherwise.
We can see that if for a certain K koko can complete the pile ,then we know that values greater than k will return True and values lesser than K will give false for the same.
so this shows our relation is monotonic in nature.

### Finding out the Search Space:
#### Finding value of L [ lower limit of search space ]:
We have to think about the minimum value which can satisfy the above equation!!
in the above problem it will be 1 since Koko has to eat at least one banana per hour
#### Finding value of R [ upper limit of search space]:
We have to think about the maximum value which can satisfy the above equation!!
in above problem it will be maximum number of bananas in any pile.

### Steps to Solve the problem:

- Initialize our low and high values as L and R.
- While low<= high, do the following:
- Find mid value and check its validity. That means check if the Predicate function is true for MID.
- If MID is valid store the value of mid as our valid answer and reduce search space by updating high=mid-1
- Else, reduce search space by moving low=mid+1;
- At the end return the valid answer.
  

## Practice Problems

1. [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/description/) 
2. [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/)
3. [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)
4. [Agressive Cows](https://www.geeksforgeeks.org/problems/aggressive-cows/0)

*Note:*  Solutions to [day21](../day21) are uploaded.
