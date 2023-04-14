function reduce(a, f, value) {
    for (let i = 0; i < a.length; i++)
        value = f(value, a[i]);
    return value;
}