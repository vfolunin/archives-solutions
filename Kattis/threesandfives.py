def get_sum(n, d):
    count = n // d
    return count * (count + 1) // 2 * d


n = int(input())
n -= 1

print(get_sum(n, 3) + get_sum(n, 5) - get_sum(n, 15))