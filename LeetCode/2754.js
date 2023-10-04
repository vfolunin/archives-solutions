Function.prototype.bindPolyfill = function(obj) {
    let f = this;
    return function(...args) {
        return f.call(obj, ...args);
    };
}