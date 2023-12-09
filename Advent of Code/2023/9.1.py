from sys import stdin


def predict(a):
    diffs = [a[i] - a[i - 1] for i in range(1, len(a))]
    return a[-1] + (predict(diffs) if any(diffs) else 0)


res = 0
for line in stdin:
    a = [int(_) for _ in line.strip().split()]
    res += predict(a)
print(res)
