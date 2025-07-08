a = eval(input())

res = 0
for value in a:
    res += value['valid'] < 2018

print(res)