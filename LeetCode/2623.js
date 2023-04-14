function memoize(f) {
    let memo = {}
    return function(...args) {
        let key = args.join();
        if (key in memo)
            return memo[key];
        return memo[key] = f(...args);
    }
}