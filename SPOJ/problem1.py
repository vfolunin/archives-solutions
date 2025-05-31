for _ in range(int(input())):
    n = int(input())
    if n:
        print(*range(n - 1, -1, -1))
    else:
        print('NOT POSSIBLE')