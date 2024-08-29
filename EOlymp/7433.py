value = int(input())
base = int(input())

digits = []
while value:
    digits.append(value % base)
    value //= base

for digit in digits[::-1]:
    if digit < 10:
        print(digit, end='')
    else:
        print(f'[{digit}]', end='')