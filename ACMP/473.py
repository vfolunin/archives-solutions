n = int(input())

fib = [1, 1]
while len(fib) <= n:
    fib.append(fib[-1] + fib[-2])

print(fib[n] * fib[n])
