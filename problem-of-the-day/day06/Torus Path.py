# Note that you can't visit all vertices on the antidiagonal (vertices (1,n),(2,n−1),…(n,1)
# ) at the same time.

# Let's prove it: since you are starting outside the antidiagonal then the only way to visit vertex (x,n+1−x)
#  is to move from (x−1,n+1−x)
#  or from (x,n−x)
# . In total, there are n
#  vertices you can move from — it's vertices (1,n−1),(2,n−2),…,(n−1,1)
#  and (n,n)
# . But (n,n)
#  is the finishing vertices you can't leave, so there are only n−1
#  positions left. As a result, you can visit at most n−1
#  vertices on the antidiagonal.

# Now, let's prove that if you've chosen a vertex (x,n+1−x)
#  you decided to skip, you can always visit all other vertices. Let's use the following simple strategy: let's move right until we meet the restricted or already visited vertex, then move down once then continue moving right and so on.

# For example, let's visit all vertices of 4×4
#  matrix except vertex (2,3)
# . The path would be the following: (1,1)
#  −
#  (1,2)
#  −
#  (1,3)
#  −
#  (1,4)
#  −
#  (2,4)
#  −
#  (2,1)
#  −
#  (2,2)
#  −
#  (3,2)
#  −
#  (3,3)
#  −
#  (3,4)
#  −
#  (3,1)
#  −
#  (4,1)
#  −
#  (4,2)
#  −
#  (4,3)
#  −
#  (4,4)
# .

# As a result, the answer is the sum of all elements minus the minimum among a[x][n+1−x]
# , or ∑ni=1∑nj=1a[i][j]−min1≤x≤n(a[x][n+1−x])
# .



def solve(A):
    s = 0
    m = A[0][-1]
    i = len(A)-1
    for r in A:
        s += sum(r)
        if r[i]<m:
            m = r[i]
        i -= 1
    return s-m
    
n = int(input())
A = []
for i in range(n):
    r = [int(x) for x in input().split()]
    A.append(r)
print(solve(A))
    
