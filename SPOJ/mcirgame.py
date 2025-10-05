from math import factorial


def solve():
    n = int(input())

    if n == -1:
        return 0

    print(factorial(n * 2) // factorial(n) // factorial(n + 1))
    return 1


while solve():
    pass