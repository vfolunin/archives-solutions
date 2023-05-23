Array.prototype.snail = function(h, w) {
    if (this.length != h * w)
        return [];

    let res = [];
    for (let y = 0; y < h; y++) {
        res.push([]);
        for (let x = 0; x < w; x++)
            res[res.length - 1].push(this[x * h + (x % 2 ? h - 1 - y : y)]);
    }
    return res;
}