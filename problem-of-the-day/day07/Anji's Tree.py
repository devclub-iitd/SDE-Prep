def help(i, s, ans, a):
    if i == 0:
        return
    if a[i][0] == 0 and a[i][1] == 0:
        ans[i] = 0
        return
    help(a[i][0], s, ans, a)
    help(a[i][1], s, ans, a)
    left = ans[a[i][0]]
    right = ans[a[i][1]]
    if left < right:
        if s[i] == 'L':
            ans[i] = left
        else:
            s[i] = 'R'
            ans[i] = 1 + left
    elif left > right:
        if s[i] == 'R':
            ans[i] = right
        else:
            s[i] = 'L'
            ans[i] = 1 + right
    else:
        if s[i] == 'U':
            ans[i] = 1 + right
        else:
            s[i] = 'L'
            ans[i] = left

def solve():
    n = int(input())
    s = input()
    a = [[0, 0] for _ in range(n + 1)]
    for i in range(1, n + 1):
        a[i][0], a[i][1] = map(int, input().split())
    s = " " + s
    ans = [n + 2] * (n + 1)
    ans[0] = n + 2
    help(1, list(s), ans, a)
    print(ans[1])

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
