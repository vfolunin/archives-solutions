s = input()

if any(c for c in s if c not in '0123456789+-*() '):
    print('WRONG')
else:
    try:
        print(eval(s))
    except:
        print('WRONG')
