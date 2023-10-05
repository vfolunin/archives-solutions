function invertObject(obj) {
    let res = {};
    for (let key in obj) {
        let value = obj[key];
        if (!res.hasOwnProperty(value))
            res[value] = key;
        else if (!Array.isArray(res[value]))
            res[value] = [res[value], key];
        else
            res[value].push(key);
    }
    return res;
}