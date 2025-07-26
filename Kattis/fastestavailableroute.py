h, w, factor = [int(_) for _ in input().split()]

res = 1
for y in range(h):
    res += input().count('.')

print(f'Your destination will arrive in {res * factor} meters')