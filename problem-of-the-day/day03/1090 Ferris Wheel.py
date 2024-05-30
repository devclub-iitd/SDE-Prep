def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    x = int(data[1])
    a = list(map(int, data[2:2+n]))
    
    a.sort()
    
    ans = 0
    i = 0
    j = n - 1
    
    while i < j:
        sum_ = a[i] + a[j]
        if sum_ <= x:
            ans += 1
            i += 1
            j -= 1
        else:
            ans += 1
            j -= 1
    
    if i == j:
        ans += 1
    
    print(ans)

if __name__ == "__main__":
    main()
