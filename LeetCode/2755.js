function deepMerge(a, b) {
    if (typeof a != 'object' || typeof b != 'object' ||
        a == null || b == null || Array.isArray(a) != Array.isArray(b))
        return b;

    let res = a;
    for (let key in b)
        res[key] = key in res ? deepMerge(res[key], b[key]) : b[key];
    return res;
};