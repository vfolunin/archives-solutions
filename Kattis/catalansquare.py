def get_catalan(n):
    res = [1]
    for i in range(1, n + 1):
        res.append(res[i - 1] * 2 * (2 * i - 1) // (i + 1))
    return res[-1]


n = int(input())

print(get_catalan(n + 1))