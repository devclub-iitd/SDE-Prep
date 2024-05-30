def main():
    n = int(input())
    s = set()
    
    for _ in range(n):
        x = int(input())
        s.add(x)
    
    print(len(s))

if __name__ == "__main__":
    main()
