export function createCounter(startValue) {
    let value = startValue;

    return {
        increment() {
            return ++value;
        },

        decrement() {
            return --value;
        },

        reset() {
            value = startValue;
            return value;
        }
    };
}