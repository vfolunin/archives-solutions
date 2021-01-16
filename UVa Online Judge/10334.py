from sys import stdin

fib = [1, 2]
for i in range(2, 1001):
    fib.append(fib[-2] + fib[-1])

for line in stdin:
    print(fib[int(line)])
