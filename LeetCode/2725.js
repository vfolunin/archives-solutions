function cancellable(f, args, ms) {
    function callF() {
        return f(...args);
    }

    callF();
    let interval = setInterval(callF, ms);

    return function() {
        clearInterval(interval);
    };
}