p, n = [int(_) for _ in input().split()]

l, r = 0, n
while l + 1 < r:
    m = (l + r) // 2
    if m ** p < n:
        l = m
    else:
        r = m

print(r)
