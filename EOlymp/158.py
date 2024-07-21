a = [1, 1, 1, 1]
while len(a) < 7100:
    a.append(a[-4] + a[-3] + a[-2] + a[-1])

n = int(input())
for i in range(n):
    print(a[int(input()) - 1])
