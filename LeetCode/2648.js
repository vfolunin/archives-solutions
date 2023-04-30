function* fibGenerator() {
    let a = 0, b = 1;
    while (1) {
        yield a;
        let c = a + b;
        a = b;
        b = c;
    }
}