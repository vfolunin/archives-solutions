Array.prototype.upperBound = function(target) {
    for (let i = this.length - 1; i >= 0; i--)
        if (this[i] == target)
            return i;
    return -1;
};