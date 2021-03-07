from sys import stdin

def solve(line):
    max_digit, n = [int(_) for _ in line.split()]

    dp = [[0 for last in range(max_digit + 1)] for len in range(n + 1)]
    for last in range(max_digit + 1):
        dp[1][last] = 1
    for len in range(2, n + 1):
        for last in range(max_digit + 1):
            dp[len][last] = dp[len - 1][last]
            if last > 0:
                dp[len][last] += dp[len - 1][last - 1]
            if last < max_digit:
                dp[len][last] += dp[len - 1][last + 1]

    print('%.5lf' % (100.0 * sum(dp[-1]) / (max_digit + 1) ** n))


for line in stdin:
    solve(line)
