from re import sub
from sys import stdin

for line in stdin:
    print(sub(r'a{1,}b{2,}c{1,}', 'QQQ', line[:-1]))
