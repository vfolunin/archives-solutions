n = int(input())

fib = [1, 2]
for i in range(2, n + 1):
    fib.append(fib[i - 2] + fib[i - 1])

print(fib[n])
