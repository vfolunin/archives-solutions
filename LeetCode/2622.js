const TimeLimitedCache = function() {
    this.cache = new Map();
};

TimeLimitedCache.prototype.set = function(key, value, ms) {
    let res = this.cache.has(key);
    
    if (res)
        clearTimeout(this.cache.get(key).timeout);
    
    function remove() {
        this.cache.delete(key);
    }
    let object = {
        value: value,
        timeout: setTimeout(remove.bind(this), ms)
    };
    this.cache.set(key, object);

    return res;
};

TimeLimitedCache.prototype.get = function(key) {
    return this.cache.has(key) ? this.cache.get(key).value : -1;
};

TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
};