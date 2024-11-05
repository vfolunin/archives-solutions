bool Factorial(int n) {
    if (n < 2)
        return 1;
    if (n == 4)
        return 0;
    
    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 1;
    
    return 0;
}
