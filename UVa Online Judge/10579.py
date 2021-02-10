from sys import stdin

fib = [0, 1]
for i in range(5000):
    fib.append(fib[-2] + fib[-1])

for line in stdin:
    print(fib[int(line)])
