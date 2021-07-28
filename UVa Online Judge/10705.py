def solve():
    bit_count = int(input())
    bit_type = input()
    number = int(input())

    code = ['0' for _ in range(bit_count)]
    code_value = 0
    n = number

    for i in range(bit_count - 1, -1, -1):
        if n % 2:
            code[i] = '1'
            if bit_type[i] == 'p':
                code_value += 2 ** (bit_count - 1 - i)
                n -= 1
            else:
                code_value -= 2 ** (bit_count - 1 - i)
                n += 1
        n //= 2

    print(''.join(code) if code_value == number else 'Impossible')


n = int(input())
for i in range(n):
    solve()
