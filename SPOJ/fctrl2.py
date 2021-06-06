f = [1]
for i in range(1, 101):
    f.append(f[-1] * i)

n = int(input())
for i in range(n):
    print(f[int(input())])
