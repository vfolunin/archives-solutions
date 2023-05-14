function chunk(a, size) {
    let res = [];
    for (let value of a) {
        if (res.length && res[res.length - 1].length < size)
            res[res.length - 1].push(value);
        else
            res.push([value]);
    }
    return res;
}