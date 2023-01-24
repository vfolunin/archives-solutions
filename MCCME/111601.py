n = int(input())

count = [0 for value in range(10)]
for c in str(n ** n):
    count[int(c)] += 1

print(*count)
