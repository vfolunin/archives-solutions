index = int(input())
a = [int(_) for _ in input().split()]

a.sort(reverse=True)

print(a[index - 1])