input()
a = [int(_) for _ in input().split()]

count = [1 for i in range(len(a))]
for i in range(1, len(a)):
    for j in range(i):
        if a[j] < a[i]:
            count[i] += count[j]

print(sum(count))
