# Let's prove that the minimum difference of consecutive elements is not greater than ⌊n2⌋
# . To do it, let's prove that larger value is not achievable. Consider element of a permutation with value ⌊n2⌋+1
# . It will have at least one adjacent element in the constructed permutation. And the maximum absolute difference of this element with the adjacent elements is at most ⌊n2⌋
# .

# Now we will construct the permutation with the minimum absolute difference of consecutive elements equals to ⌊n2⌋
# . Assign x=⌊n2+1⌋
# . Now we can construct such permutation: x,1,x+1,2,x+2,…
# . It's easy to see that the minimum absolute difference of consecutive elements equals to x−1
# .


for _ in range(int(input())):
    d=int(input())
    x=d//2 +1
    for i in range(d//2):
        print(x+i,end=" ")
        print(i+1,end=" ")
    if d%2!=0 :
        print(d)
    print()  