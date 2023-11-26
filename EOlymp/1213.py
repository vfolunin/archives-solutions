a, b = input().split()

a_parts = [int(_) for _ in a.split('^')]
b_parts = [int(_) for _ in b.split('^')]

if a_parts[0] ** a_parts[1] > b_parts[0] ** b_parts[1]:
    print(a)
else:
    print(b)
