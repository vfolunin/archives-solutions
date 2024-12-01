from sys import stdin

a, b = [], []
for line in stdin:
    a_value, b_value = [int(_) for _ in line.split()]
    a.append(a_value)
    b.append(b_value)

a.sort()
b.sort()

res = 0
for i in range(len(a)):
    res += abs(a[i] - b[i])

print(res)
