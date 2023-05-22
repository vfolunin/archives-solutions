n = int(input())

if n % 3 == 0:
    print(3 ** (n // 3))
elif n % 3 == 1:
    print(3 ** ((n - 4) // 3) * 4 if n > 1 else 1)
else:
    print(3 ** ((n - 2) // 3) * 2)
