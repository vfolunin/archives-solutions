N = 901

c = [[0 for j in range(N)] for i in range(N)]
for n in range(N):
    c[n][0] = 1
    for k in range(1, n + 1):
        c[n][k] = c[n - 1][k] + c[n - 1][k - 1]

res = [1 for i in range(N)]
for n in range(1, N):
    res[n] = sum(c[n - 1][k] * res[k] for k in range(n))

while True:
    n = int(input())
    if not n:
        break
    print(n, res[n], sep=', ')
