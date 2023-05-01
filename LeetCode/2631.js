Array.prototype.groupBy = function(f) {
    let res = {};
    for (let value of this) {
        let key = f(value);
        if (!res.hasOwnProperty(key))
            res[key] = [];
        res[key].push(value);
    }
    return res;
};