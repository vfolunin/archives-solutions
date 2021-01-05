for i in range(int(input())):
    a, b = [int(token[::-1]) for token in input().split()]
    print(int(str(a + b)[::-1]))
