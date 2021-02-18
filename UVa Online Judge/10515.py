def pow(n, p):
    if not p:
        return 1
    if p % 2:
        return pow(n, p - 1) * n % 10
    r = pow(n, p // 2)
    return r * r % 10

def solve():
    a, b = [int(_) for _ in input().split()]
    if not a and not b:
        return 0
    print(pow(a % 10, b))
    return 1

while (solve()):
    pass
