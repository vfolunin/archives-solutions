s = input()

print(sum(ord(c) - ord('a') + 1 for c in s))