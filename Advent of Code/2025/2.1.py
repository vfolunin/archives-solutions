segments = [[int(_) for _ in segment.split('-')] for segment in input().split(',')]

res = 0
for half in range(1, 10 ** 5):
    value = half * (10 ** len(str(half))) + half
    for l, r in segments:
        if l <= value <= r:
            res += value

print(res)
