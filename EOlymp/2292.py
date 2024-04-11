fib = [0, 1]
for i in range(2, 10001):
    fib.append(fib[-1] + fib[-2])

query_count = int(input())
for i in range(query_count):
    print(fib[int(input())])
