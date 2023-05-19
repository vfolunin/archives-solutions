Function.prototype.callPolyfill = function(context, ...args) {
    return this.bind(context)(...args);
};