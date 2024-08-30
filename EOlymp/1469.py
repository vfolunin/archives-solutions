from sys import stdin

fib = [0, 1]
for i in range(2, 1000):
    fib.append(fib[-1] + fib[-2])

for line in stdin:
    print(fib[int(line)])
