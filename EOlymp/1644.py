def to_int(s):
    parts = s.split('.')
    res = int(parts[0])
    for i in range(9):
        res *= 10
        if len(parts) > 1 and i < len(parts[1]):
            res += int(parts[1][i])
    return res


num, den = [to_int(_) for _ in input().split()]

print(num // den)
