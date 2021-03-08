from sys import stdin


def solve(arr):
    res = arr[0]
    for l in range(len(arr)):
        product = 1
        for r in range(l, len(arr)):
            product *= arr[r]
            res = max(res, product)
    print(res)


for line in stdin:
    solve([int(_) for _ in line.split()[:-1]])
