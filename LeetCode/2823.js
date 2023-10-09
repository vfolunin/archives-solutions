function deepFilter(obj, f) {
    if (obj == null || typeof obj != 'object')
        return f(obj) ? obj : undefined;
    
    if (Array.isArray(obj)) {
        let res = [];
        for (let value of obj) {
            let resValue = deepFilter(value, f);
            if (resValue !== undefined)
                res.push(resValue);
        }
        return res.length ? res : undefined;
    }

    let res = {};
    for (let key in obj) {
        let resValue = deepFilter(obj[key], f);
        if (resValue !== undefined)
            res[key] = resValue;
    }
    return Object.keys(res).length ? res : undefined;
}