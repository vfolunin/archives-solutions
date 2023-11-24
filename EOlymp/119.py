target_size = len(input())

res, power, size = 1, 2, 1
while size < target_size:
    res += 1
    power *= 2
    size += len(str(power))

print(res)
