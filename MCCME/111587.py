sa = input()
sb = input()

fib = [1, 2]
while len(fib) < 10005:
    fib.append(fib[-1] + fib[-2])

a = sum(fib[i] for i in range(len(sa)) if sa[len(sa) - 1 - i] == '1')
b = sum(fib[i] for i in range(len(sb)) if sb[len(sb) - 1 - i] == '1')
c = a + b

i = len(fib) - 1
while c < fib[i]:
    i -= 1

res = []
while i >= 0:
    if c >= fib[i]:
        res.append(1)
        c -= fib[i]
    else:
        res.append(0)
    i -= 1

print(''.join([str(_) for _ in res]))
