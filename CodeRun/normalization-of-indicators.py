input()
a = sorted([int(_) for _ in input().split()])

query_count = int(input())

for i in range(query_count):
    value = int(input())

    l, r = -1, len(a)
    while l + 1 < r:
        m = l + (r - l) // 2
        if a[m] < value:
            l = m
        else:
            r = m

    print(a[l] if r == len(a) or l != -1 and value - a[l] <= a[r] - value else a[r])