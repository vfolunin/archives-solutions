from math import factorial


def solve():
    n = int(input())

    if n < 0:
        print('accept positive integer only!')
        return

    print(n, end='!=')
    if n > 1:
        for i in range(1, n):
            print(i, end='*')
        print(n, end='=')
    print(factorial(n))


n = int(input())

for i in range(n):
    solve()