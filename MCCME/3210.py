from re import findall

regex = input()
text = input()

try:
    for s in findall(regex, text):
        print(s)
except:
    print('Runtime Error')