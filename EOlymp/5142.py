from math import factorial


def anagram_count(letter_count):
    res = factorial(sum(letter_count))
    for count in letter_count:
        res //= factorial(count)
    return res


s = input()

letter_count = [0 for i in range(26)]
for c in s:
    letter_count[ord(c) - ord('a')] += 1

res = 0
for c in s:
    for i in range(ord(c) - ord('a')):
        if letter_count[i]:
            letter_count[i] -= 1
            res += anagram_count(letter_count)
            letter_count[i] += 1
    letter_count[ord(c) - ord('a')] -= 1

print(res)
