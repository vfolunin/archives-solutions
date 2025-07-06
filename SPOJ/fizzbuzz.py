for _ in range(int(input())):
    n = int(input())
    if n % 35 == 0:
        print('fizzbuzz')
    elif n % 5 == 0:
        print('fizz')
    elif n % 7 == 0:
        print('buzz')
    else:
        print(n)