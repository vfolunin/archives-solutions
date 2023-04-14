function memoize(f) {
    let id = new Map;
    function getId(arg) {
        if (!id.has(arg))
            id.set(arg, id.size);
        return id.get(arg);
    }

    let memo = {};
    return function(...args) {
        let key = args.map(getId).join();
        if (key in memo)
            return memo[key];
        return memo[key] = f(...args);
    }
}