n = int(input())

fib = [0, 1]
while len(fib) <= n:
    fib.append(fib[-2] + fib[-1])

print(fib[n])
