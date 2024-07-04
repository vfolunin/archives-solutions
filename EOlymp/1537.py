from math import comb


def solve():
    length, number_count, *numbers = [int(_) for _ in input().split()]
    print(comb(length - sum(numbers) + 1, number_count))


n = int(input())
for i in range(n):
    solve()
