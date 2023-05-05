n = int(input())
k = int(input())

combinations = 1
for i in range(k):
    combinations *= n - i
    combinations //= i + 1

print(combinations)
