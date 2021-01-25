from sys import stdin

def polynomial(coeffs, x):
    res = 0
    for coeff in coeffs:
        res = res * x + coeff
    return res

lines = stdin.readlines()
for i in range(0, len(lines), 2):
    coeffs = [int(_) for _ in lines[i].split()]
    xs = [int(_) for _ in lines[i + 1].split()]
    print(' '.join(str(polynomial(coeffs, x)) for x in xs))
