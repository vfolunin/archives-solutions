def rec(n, angles):
    if not n:
        print('go(5)')
        return
    rec(n - 1, angles)
    for angle in angles:
        print(f'turn({angle})')
        rec(n - 1, angles)


angles = input()[1:-1].split('-')
n = int(input())
rec(n, angles)
