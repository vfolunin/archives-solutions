def solve():
    num, den = [int(_) for _ in input().split()]

    res = 0
    while num >= den:
        count = num // den
        res += count * den
        num = num % den + count

    print(res + num)


n = int(input())

for i in range(n):
    solve()