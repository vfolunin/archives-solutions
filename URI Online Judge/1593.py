def solve():
    n = int(input())

    ones = 0
    while n:
        ones += 1
        n &= n - 1
    
    print(ones)


n = int(input())
for i in range(n):
    solve()
