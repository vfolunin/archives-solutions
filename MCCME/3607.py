from re import sub
from sys import stdin

for line in stdin:
    print(sub(r'\\circle{\((\d+),(\d+)\)', r'\\circle{(\2,\1)', line[:-1]))
