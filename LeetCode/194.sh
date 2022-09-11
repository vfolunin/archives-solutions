python3 -c "
rows = []
for line in open('file.txt'):
    rows.append(line.split())
for row in zip(*rows):
    print(*row)
"