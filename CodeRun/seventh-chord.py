from bisect import  bisect_left


def can(a, threshold):
    return len(a) - bisect_left(a, threshold * threshold) >= threshold


input()
a = sorted([int(_) for _ in input().split()])

l, r = -1, len(a) + 1
while l + 1 < r:
    m = l + (r - l) // 2
    if can(a, m):
        l = m
    else:
        r = m

print(l)