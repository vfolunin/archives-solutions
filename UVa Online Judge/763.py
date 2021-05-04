from sys import stdin

f = [1, 2]
for i in range(100):
    f.append(f[-1] + f[-2])


def to_dec(s):
    res = 0
    for i in range(len(s)):
        if s[i] == '1':
            res += f[len(s) - 1 - i]
    return res


def to_fib(n):
    if not n:
        return '0'
    res = ''
    i = len(f) - 1
    while f[i] > n:
        i -= 1
    while i >= 0:
        if n >= f[i]:
            res += '1'
            n -= f[i]
        else:
            res += '0'
        i -= 1
    return res


def solve(a, b):
    print(to_fib(to_dec(a) + to_dec(b)))


lines = [line.strip() for line in stdin.readlines() if line.strip()]
for i in range(0, len(lines), 2):
    if i:
        print()
    solve(lines[i], lines[i + 1])
