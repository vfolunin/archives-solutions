n = int(input())

l, r = 1, 1
while r * r <= n:
    r *= 2

while l + 1 < r:
    m = l + (r - l) // 2
    if m * m <= n:
        l = m
    else:
        r = m

print(l)
