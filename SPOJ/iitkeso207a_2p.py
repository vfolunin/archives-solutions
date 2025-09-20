size = int(input())
expr = ''.join([input() for _ in range(size)])

try:
    print(eval(expr))
except:
    print('Malformed expression')