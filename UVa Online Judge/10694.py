fib = [0, 1]
for i in range(2, 1000):
    fib.append(fib[-2] + fib[-1])
for t in range(2):
    for i in range(1, 1000):
        fib[i] += fib[i - 1]

n = int(input())
for i in range(n):
    x = int(input())
    print(fib[x] if x > 0 else 0)
