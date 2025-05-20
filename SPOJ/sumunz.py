a = eval(input())

res = 0
for value in a:
    if value:
        res += value
    else:
        break

print(res)