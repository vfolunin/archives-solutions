def rec(n):
    if not n:
        print('go(5)')
        return
    rec(n - 1)
    print('turn(90)')
    rec(n - 1)
    print('turn(-90)')
    rec(n - 1)
    print('turn(-90)')
    rec(n - 1)
    print('turn(90)')
    rec(n - 1)


n = int(input())
rec(n)
print('turn(90)')
rec(n)
print('turn(90)')
rec(n)
print('turn(90)')
rec(n)
