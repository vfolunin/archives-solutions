function ArrayWrapper(a) {
    this.a = a;
}

ArrayWrapper.prototype.valueOf = function() {
    let sum = 0;
    for (let value of this.a)
        sum += value;
    return sum;
};

ArrayWrapper.prototype.toString = function() {
    let s = "[";
    for (let i = 0; i < this.a.length; i++) {
        s += this.a[i].toString();
        if (i + 1 < this.a.length)
            s += ",";
    }
    s += "]";
    return s;
};