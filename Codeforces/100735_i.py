values = [int(input()) for _ in range(3)]

for a in values:
    for b in values:
        for c in values:
            if a + b == c:
                print('YES')
                exit(0)

print('NO')