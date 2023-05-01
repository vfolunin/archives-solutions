function curry(f) {
    return function curried(...args) {
        if (args.length == f.length)
            return f(...args);

        return function(...remainingArgs) {
            return curried(...args, ...remainingArgs);
        };
    };
}