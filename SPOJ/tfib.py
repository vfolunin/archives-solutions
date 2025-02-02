fib, a, b = [], 0, 1
while b <= 10 ** 100:
    a, b = b, a + b
    fib.append(b)

while 1:
    l, r = [int(_) for _ in input().split()]
    if not l and not r:
        break
    print(sum(1 for f in fib if l <= f <= r))
