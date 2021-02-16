from sys import stdin

def remove_trailing_zeros(n):
    n_len = len(n)
    while n_len > 1 and n[n_len - 1] == '0':
        n_len -= 1
    return n[:n_len]

def solve(line):
    n, power = line.split()
    n = remove_trailing_zeros(n)
    divisor_power = len(n) - 1 - n.index('.')
    n, power = int(n.replace('.', '')), int(power)

    result = str(n ** power)
    divisor_power *= power

    result_len = len(result)
    if result_len < divisor_power:
        result = '0' * (divisor_power - result_len) + result

    result_len = len(result)
    result = result[:result_len - divisor_power] + '.' + result[result_len - divisor_power:]

    result = remove_trailing_zeros(result)
    print(result)

for line in stdin:
    solve(line)
