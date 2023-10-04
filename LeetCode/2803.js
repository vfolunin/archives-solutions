function* factorial(n) {
    if (!n)
        yield 1;
    
    let res = 1;
    for (let i = 1; i <= n; i++) {
        res *= i;
        yield res;
    }
}