let CustomInterval = (function() {
    let timeouts = new Map();
    let nextId = 0;

    function rec(id, f, delay, period, callCount) {
        timeouts.set(id, setTimeout(function() {
            f();
            rec(id, f, delay, period, callCount + 1);
        }, delay + period * callCount));
    }

    function setInterval(f, delay, period) {
        rec(nextId, f, delay, period, 0);
        return nextId++;
    }

    function clearInterval(id) {
        clearTimeout(timeouts.get(id));
        timeouts.delete(id);
    }

    return { setInterval, clearInterval };
})();

function customInterval(f, delay, period) {
    return CustomInterval.setInterval(f, delay, period);
}

function customClearInterval(id) {
    CustomInterval.clearInterval(id);
}