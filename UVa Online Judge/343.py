from sys import stdin

def get_min_base(number):
    digits = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    base = 1
    for digit in number:
        base = max(base, digits.index(digit))
    return base + 1

for line in stdin:
    a, b = line.strip().split()

    bases = {}
    for base in range(get_min_base(a), 37):
        value = int(a, base=base)
        if value not in bases:
            bases[value] = base

    found = 0
    for base in range(get_min_base(b), 37):
        value = int(b, base=base)
        if value in bases:
            found = 1
            print('{} (base {}) = {} (base {})'.format(a, bases[value], b, base))
            break

    if not found:
        print('{} is not equal to {} in any base 2..36'.format(a, b))
