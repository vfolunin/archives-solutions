function createInfiniteObject() {
    return new Proxy({}, {
        get: function(target, key) {
            return function() {
                return String(key);
            };
        }
    });
}