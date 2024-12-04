from sys import stdin

a = [line.strip() for line in stdin]

dy = [-1, -1, -1, 0, 1, 1, 1, 0]
dx = [-1, 0, 1, 1, 1, 0, -1, -1]
s = 'XMAS'
res = 0

for y in range(len(a)):
    for x in range(len(a[0])):
        for d in range(len(dy)):
            ok = 1
            for i in range(len(s)):
                ty = y + dy[d] * i
                tx = x + dx[d] * i
                ok &= 0 <= ty < len(a) and 0 <= tx < len(a[0]) and a[ty][tx] == s[i]
            res += ok

print(res)
