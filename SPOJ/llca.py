from sys import stdin

for s in stdin:
    try:
        k, a, b = [int(_) for _ in s.split()]
    except:
        continue

    while a != b:
        if a > b:
            a, b = b, a
        b = (b - 2) // k + 1

    print(a)
