s = 0
for i in range(5):
    s += int(input())

print(s / 5 if s % 2 else s / 2)