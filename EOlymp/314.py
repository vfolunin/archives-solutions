n = int(input())

for i in range(n):
    s = input()
    if '+' in s:
        a, b = [int(_) for _ in s.split('+')]
        print(a + b)
    else:
        a, b = [int(_) for _ in s.split('-')]
        print(a - b)