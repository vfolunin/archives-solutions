def from_dec(n, base):
    res = []
    while n >= base:
        res.append(n % base)
        n //= base
    res.append(n)
    return ''.join(str(_) for _ in res[::-1])

while 1:
    line = input()
    if line == '0':
        break

    tokens = line.split()
    base = int(tokens[0])
    value = int(tokens[1], base=base)
    mod = int(tokens[2], base=base)
    print(from_dec(value % mod, base))
