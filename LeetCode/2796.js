String.prototype.replicate = function(n) {
    res = '';
    for (let i = 0; i < n; i++)
        res += this;
    return res;
}