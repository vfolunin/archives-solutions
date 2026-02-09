input()
s = input()

best_len = len(s) + 1
mid = []

for i in range(1, len(s)):
    if s[i] == '0':
        continue

    left_len = i
    right_len = len(s) - i
    cur_len = max(left_len, right_len) + 1

    if best_len > cur_len:
        best_len = cur_len
        mid = [i]
    elif best_len == cur_len:
        mid.append(i)

print(min(int(s[:m]) + int(s[m:]) for m in mid))