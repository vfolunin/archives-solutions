function throttle(f, ms) {
    let canExecute = 1;
    let storedArgs = null;
    
    function throttled() {
        if (storedArgs != null) {
            f(...storedArgs);
            storedArgs = null;
            setTimeout(throttled, ms);
        } else {
            canExecute = 1;
        }
    }
    
    return function(...args) {
        if (canExecute) {
            f(...args);
            canExecute = 0;
            setTimeout(throttled, ms);
        } else {
            storedArgs = args;
        }
    };
}