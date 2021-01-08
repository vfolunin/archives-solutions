while 1:
    n = int(input())
    if not n:
        break

    factorial = 1
    for digit in range(2, n + 1):
        factorial *= digit

    digit_count = [0] * 10
    while factorial:
        digit_count[factorial % 10] += 1
        factorial //= 10

    print('{}! --'.format(n))
    for start_digit in [0, 5]:
        row = []
        for digit in range(start_digit, start_digit + 5):
            row.append('   ({}){:5}'.format(digit, digit_count[digit]))
        print(' '.join(row))
