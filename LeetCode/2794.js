function createObject(keys, values) {
    let res = {};
    for (let i = 0; i < keys.length; i++)
        if (!res.hasOwnProperty(keys[i]))
            res[keys[i]] = values[i];
    return res;
}