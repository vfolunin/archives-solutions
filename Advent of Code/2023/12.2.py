from sys import stdin


def rec(s, si, a, ai, memo):
    if (si, ai) in memo:
        return memo[si, ai]

    if si < 0:
        return si == -1 and ai == -1
    if ai < 0:
        return all(s[i] != '#' for i in range(si + 1))

    res = 0
    if s[si] != '#':
        res += rec(s, si - 1, a, ai, memo)
    if all(si >= i and s[si - i] != '.' for i in range(a[ai])) and (ai == 0 or s[si - a[ai]] != '#'):
        res += rec(s, si - a[ai] - (ai != 0), a, ai - 1, memo)

    memo[si, ai] = res
    return res


def solve(line):
    s, a = line.split()
    s = '?'.join([s for _ in range(5)])
    a = [int(_) for _ in a.split(',')] * 5
    memo = {}
    return rec(s, len(s) - 1, a, len(a) - 1, memo)


res = 0
for line in stdin:
    res += solve(line.strip())
print(res)
