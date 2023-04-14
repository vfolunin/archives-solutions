function map(a, f) {
    let res = [];
    for (let i = 0; i < a.length; i++)
        res.push(f(a[i], i));
    return res;
}