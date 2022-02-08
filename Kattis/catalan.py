catalan = [1]
for i in range(5001):
    catalan.append(catalan[-1] * 2 * (2 * i + 1) // (i + 2))


def solve():
    n = int(input())
    print(catalan[n])


n = int(input())
for i in range(n):
    solve()
