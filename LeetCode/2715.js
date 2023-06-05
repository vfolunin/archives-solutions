function cancellable(f, args, ms) {
    let timeout = setTimeout(function() {
        return f(...args);
    }, ms);

    return function() {
        clearTimeout(timeout);
    };
}