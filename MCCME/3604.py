from re import sub
from sys import stdin

for line in stdin:
    line = sub(r'\$v_([\dA-Za-z])\$', r'v[\1]', line[:-1])
    print(sub(r'\$v_{([\dA-Za-z]+)}\$', r'v[\1]', line))
