n = int(input())

a = [1, 2]
for i in range(2, n + 1):
    a.append(a[-1] + a[-2])

print(a[n])
