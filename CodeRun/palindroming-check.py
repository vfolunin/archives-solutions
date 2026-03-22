s = input().lower().replace(' ', '')

if s == s[::-1]:
    print('It is a palindrome')
else:
    print('It is not a palindrome')