from sys import stdin


def derivative(coeffs, x):
    n, res = len(coeffs) - 1, 0
    for i in range(n):
        res = res * x + coeffs[i] * (n - i)
    return res


lines = stdin.readlines()
for i in range(0, len(lines), 2):
    x = int(lines[i])
    coeffs = [int(_) for _ in lines[i + 1].split()]
    print(derivative(coeffs, x))
