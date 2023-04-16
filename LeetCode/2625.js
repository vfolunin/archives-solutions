function flat(a, depth) {
    let res = [];
    
    for (let i = 0; i < a.length; i++) {
        if (depth && Array.isArray(a[i]))
            res.push(...flat(a[i], depth - 1));
        else
            res.push(a[i]);
    }

    return res;
}