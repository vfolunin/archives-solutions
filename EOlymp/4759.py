a = [int(_) for _ in input().split()]

print([value * value for value in a])
print([value % 11 for value in a])
print([value for value in a if value % 2 == 0])
print([value for value in a if len(str(abs(value))) % 2])
print([value * 100 + value for value in a if 10 <= value < 100])
print([a[i] for i in range(len(a)) if i % 3])
