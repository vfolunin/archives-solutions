module.exports = function merge(a, aSize, b, bSize) {
    let ai = aSize - 1, bi = bSize - 1;
    for (let i = aSize + bSize - 1; i >= 0; i--) {
        if (bi < 0 || ai >= 0 && a[ai] >= b[bi])
            a[i] = a[ai--];
        else
            a[i] = b[bi--];
    }
}