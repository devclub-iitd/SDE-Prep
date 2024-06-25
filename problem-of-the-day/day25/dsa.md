# Sieve Algorithm (Date: 25/06/2024)

Today, we will learn about the Sieve algorithm, which is used to find all prime numbers between [1, n] in \(O(n \log \log n)\) time complexity.

## Logic Behind the Algorithm

The algorithm is very simple: at the beginning, we write down all numbers between 2 and \( n \). We mark all proper multiples of 2 (since 2 is the smallest prime number) as composite. A proper multiple of a number \( x \) is a number greater than \( x \) and divisible by \( x \). Then we find the next number that hasn't been marked as composite, which in this case is 3. This means 3 is prime, and we mark all proper multiples of 3 as composite. The next unmarked number is 5, which is the next prime number, and we mark all proper multiples of it. We continue this procedure until we have processed all numbers in the range.

The idea behind this is: A number is prime if none of the smaller prime numbers divides it. Since we iterate over the prime numbers in order, we have already marked all numbers divisible by at least one of the smaller prime numbers as composite. Hence, if we reach a cell that is not marked, it isn't divisible by any smaller prime number and therefore has to be prime.

## Optimization

While marking all the proper divisors of a selected prime number as composite, we can start from the square of the selected prime number. Any number smaller than that, if composite, would have already been marked by prime numbers smaller than this selected prime number (since all composite numbers have a prime factor smaller than or equal to their square root).

## Problems to Practice

1. [Noldback Problem](https://codeforces.com/problemset/problem/17/A)
2. [Count Primes](https://leetcode.com/problems/count-primes/description/)
3. [Sherlock and His Girlfriend](https://codeforces.com/contest/776/problem/B)
4. [Four Divisors](https://leetcode.com/problems/four-divisors/description/)
