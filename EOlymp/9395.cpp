int CountDivisors(int n) {
    int res = 0;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            res++;
            res += d * d != n;
        }
    }
    return res;
}
