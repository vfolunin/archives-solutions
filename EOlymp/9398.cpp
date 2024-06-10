long long solve(long long n) {
    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return d;
    return n;
}
