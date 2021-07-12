n = int(input())
for i in range(n):
    try:
        print(eval(input()))
    except:
        print('ERROR')
