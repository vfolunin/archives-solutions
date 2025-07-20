input()
expr = input().replace('<]:=', '0').replace('/', '//')

res = eval(expr)

print(str(res).replace('0', '<]:='))