function debounce(f, ms) {
    let timeout;
    return function(...args) {
        clearTimeout(timeout);
        timeout = setTimeout(function() {
            f(...args);
        }, ms);
    };
}