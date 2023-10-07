function makeImmutable(obj) {
    return new Proxy(obj, {
        set : function(target, key) {
            if (Array.isArray(target))
                throw `Error Modifying Index: ${key}`;
            throw `Error Modifying: ${key}`;
        },

        get : function(target, key) {
            if (key == 'prototype' || target[key] == null ||
                typeof target[key] != 'object' && typeof target[key] != 'function')
                return target[key];
            return new Proxy(target[key], this);
        },

        apply : function(target, obj, args) {
            let methods = new Set(['pop', 'push', 'shift', 'unshift', 'splice', 'sort', 'reverse']);
            if (methods.has(target.name))
                throw `Error Calling Method: ${target.name}`;
            return target.apply(obj, args);
        }
    });
};
