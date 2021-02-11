def gcd(a, b):
    return gcd(b, a % b) if b else a

n = int(input())
for test in range(1, n + 1):
    a = int(input(), base=2)
    b = int(input(), base=2)
    print('Pair #', test, ':', sep='', end=' ')
    if gcd(a, b) > 1:
        print('All you need is love!')
    else:
        print('Love is not all you need!')
