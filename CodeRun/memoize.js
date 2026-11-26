export function memoize(f) {
    let memo = new Map();

    return function(...args) {
        const key = JSON.stringify(args);
        if (!memo.has(key))
            memo.set(key, f(...args));
        return memo.get(key);
    };
}