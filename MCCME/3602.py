from re import sub
from sys import stdin

for line in stdin:
    print(sub(r'\$v_([\dA-Za-z])\$', r'v[\1]', line[:-1]))
