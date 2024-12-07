from sys import stdin


def rec(target, cur, a, i):
    if i == len(a):
        return target == cur
    return (rec(target, cur + a[i], a, i + 1) or
            rec(target, cur * a[i], a, i + 1))


res = 0

for line in stdin:
    target, a = line.strip().split(': ')
    target = int(target)
    a = [int(_) for _ in a.split()]
    if rec(target, a[0], a,1):
        res += target

print(res)
