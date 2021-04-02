res = [0]
for i in range(1, 100):
    res.append((res[-1] + i ** i) % 10)


def solve():
    n = int(input())
    if not n:
        return 0
    print(res[n % 100])
    return 1


while solve():
    pass
