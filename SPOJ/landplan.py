def solve():
    size = int(input())
    for y in range(size):
        for x in range(size):
            print('.' if 0 < y < size - 1 and 0 < x < size - 1 else '#', end='')
        print()
    print()


n = int(input())
for i in range(n):
    solve()