from itertools import permutations
from sys import stdin


def encode_digit(code, digit):
    segment_combinations = ['012456', '25', '02346', '02356', '1235', '01356', '013456', '025', '0123456', '012356']
    return ''.join(sorted(code[int(segment)] for segment in segment_combinations[digit]))


def decode_digit(code, encoded_digit):
    for digit in range(10):
        if encode_digit(code, digit) == encoded_digit:
            return digit


def decode_number(code, encoded_number):
    res = 0
    for encoded_digit in encoded_number:
        res = res * 10 + decode_digit(code, ''.join(sorted(encoded_digit)))
    return res


def get_syndrome(code):
    return set(encode_digit(code, digit) for digit in range(10))


def get_code(syndrome):
    for code in permutations('abcdefg'):
        if syndrome == get_syndrome(code):
            return ''.join(code)


output_sum = 0
for line in stdin:
    syndrome, encoded_number = [part.split() for part in line.split(' | ')]
    code = get_code(set(''.join(sorted(encoded_digit)) for encoded_digit in syndrome))
    output_sum += decode_number(code, encoded_number)

print(output_sum)
