from math import gcd
from sys import stdin

for line in stdin:
    a, b = [int(_) for _ in line.split()]
    
    if a == 0 and b == 0:
        break

    print(gcd(a, b))