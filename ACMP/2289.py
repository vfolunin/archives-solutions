from math import comb
from sys import set_int_max_str_digits

set_int_max_str_digits(10000)

p = int(input())

print((comb(2 * p, p) + 2 * p - 2) // p)
