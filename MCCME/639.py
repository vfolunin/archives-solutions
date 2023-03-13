def from_dec(n, base):
    digits = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    res = ''
    while n >= base:
        res += digits[n % base]
        n //= base
    res += digits[n]
    return res[::-1]


base_from, base_to = [int(_) for _ in input().split()]
value = int(input(), base=base_from)

print(from_dec(value, base_to))
