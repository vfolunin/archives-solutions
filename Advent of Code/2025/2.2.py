segments = [[int(_) for _ in segment.split('-')] for segment in input().split(',')]

values = set()
for part in range(1, 10 ** 5):
    for count in range(2, 20 // len(str(part)) + 1):
        value = int(str(part) * count)
        for l, r in segments:
            if l <= value <= r:
                values.add(value)
                break

print(sum(values))
