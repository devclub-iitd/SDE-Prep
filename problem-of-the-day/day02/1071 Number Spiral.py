# Number Spiral
# A number spiral is an infinite grid whose upper-left square has number 1
# Your task is to find out the number in row y and column x

test = int(input())

for i in range(test):
    y, x = map(int, input().split())

    if y > x:
        if y % 2:
            ans = (y - 1) ** 2 + x
        else:
            ans = y ** 2 - x + 1
    else:
        if x % 2:
            ans = x ** 2 - y + 1
        else:
            ans = (x - 1) ** 2 + y

    print(ans)
