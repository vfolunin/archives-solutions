input()
s = input()
a = [int(_) for _ in input().split()]

res = ''
res_time = 0
for i in range(len(s)):
    time = a[i] - (a[i - 1] if i else 0)
    if res_time <= time:
        res = s[i]
        res_time = time

print(res)