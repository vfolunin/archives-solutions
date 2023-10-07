function* cycleGenerator(a, i) {
    while (1) {
        delta = yield a[i];
        i = ((i + delta) % a.length + a.length) % a.length;
    }
}