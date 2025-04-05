from re import sub
from sys import stdin

for line in stdin:
    print(sub(r'(([A-Z][A-Za-z]*)(\s+[A-Z][A-Za-z]*){2,})', r'"\1"', line[:-1]))
