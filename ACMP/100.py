n = int(input())
n //= 2

count = [[0 for sum in range(9 * n + 1)] for len in range(n + 1)]
count[0][0] = 1

for len in range(1, n + 1):
    for sum in range(0, 9 * n + 1):
        for digit in range(min(10, sum + 1)):
            count[len][sum] += count[len - 1][sum - digit]

res = 0
for sum in range(0, 9 * n + 1):
    res += count[n][sum] * count[n][sum]

print(res)
