a = [int(_) for _ in input().split()]

for i in range(25):
    b = []
    for value in a:
        s = str(value)
        if len(s) % 2 == 0:
            b.append(int(s[:len(s) // 2]))
            b.append(int(s[len(s) // 2:]))
        else:
            b.append(max(value * 2024, 1))
    a = b[:]

print(len(a))