h = int(input())
while (h * (h + 1) // 2 * 3 - h) % 4:
    h += 1
print(h)
