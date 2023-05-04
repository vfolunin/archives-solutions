function createCounter(init) {
    let value = init;
    return {
        increment: function() {
            return ++value;
        },
        decrement: function() {
            return --value;
        },
        reset: function() {
            return value = init;
        }
    };
}