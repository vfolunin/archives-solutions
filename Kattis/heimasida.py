s = input()

s = [c.lower() for c in s if c.isalnum()]

signs = 'á ð é í ó ú ý þ æ ö'.split()
letters = 'a d e i o u y th ae o'.split()
for i in range(len(s)):
    if s[i] in signs:
        s[i] = letters[signs.index(s[i])]

print(''.join(s) + '.is')