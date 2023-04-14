function filter(a, f) {
    let res = [];
    for (let i = 0; i < a.length; i++)
        if (f(a[i], i))
            res.push(a[i]);
    return res;
}