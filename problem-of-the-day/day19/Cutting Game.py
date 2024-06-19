T = int(input())
big = float('inf')
for _ in range(T):
    m, x = map(int, input().split())
    c = []
    h = []
    for i in range(m):
        ci, hi = map(int, input().split())
        c.append(ci)
        h.append(hi)
    mh = sum(h)
    dp = [0] + [big] * mh
    for i in range(m):
        for j in range(mh, h[i]-1, -1):
            if dp[j-h[i]] + c[i] <= i*x:
                dp[j] = min(dp[j], dp[j-h[i]]+c[i])
    for i in range(mh, -1, -1):
        if dp[i] != big:
            print(i)
            break