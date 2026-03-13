size = int(input())

res = [1, 1, 2, 4]
for i in range(4, 70):
    res.append(sum(res[i - 4:i]))

for i in range(size):
    n = int(input())
    print(res[n])