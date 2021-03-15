row = [1]
while True:
    print(*row)
    if max(row) >= 10 ** 60:
        break
    row = [1] + [row[i] + row[i + 1] for i in range(len(row) - 1)] + [1]
