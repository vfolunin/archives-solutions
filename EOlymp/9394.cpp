int suma(int n) {
    n = abs(n);
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
