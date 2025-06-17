fib = [0, 1]
for i in range(90):
    fib.append(fib[-1] + fib[-2])

n = int(input())

for i in range(n):
    index = int(input())

    print(fib[index + 1] - 1)