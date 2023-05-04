function once(f) {
    let called = false;
    return function(...args) {
        if (called) {
            return undefined;
        } else {
            called = true;
            return f(...args);
        }
    };
}