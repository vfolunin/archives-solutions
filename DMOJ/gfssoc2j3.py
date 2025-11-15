s = input()[:-2]

s = s.replace('P', '+')
s = s.replace('M', '-')

print(eval(s))