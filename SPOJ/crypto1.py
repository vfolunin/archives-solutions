from time import asctime, gmtime

value = int(input())

mod = 4000000007
res = pow(value, (mod + 1) // 4, mod)
if res * 2 > mod:
    res = mod - res

print(asctime(gmtime(res)))
