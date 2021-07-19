from math import factorial

def solve():
    s = input()
    index = int(input()) - 1

    p = s[0]

    group_size = factorial(len(s))
    for i in range(1, len(s)):
        group_size //= i + 1
        pos = index // group_size
        index %= group_size
        p = p[:pos] + s[i] + p[pos:]

    print(p)


n = int(input())
for i in range(n):
    solve()
