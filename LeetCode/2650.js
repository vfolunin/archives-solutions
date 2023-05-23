function cancellable(generator) {
    let cancelFunction;

    let cancelPromise = new Promise(function(_, reject) {
        cancelFunction = function() {
            reject("Cancelled");
        }
    });

    async function getPromise() {
        let next = generator.next();
        while (!next.done) {
            try {
                next = generator.next(await Promise.race([next.value, cancelPromise]));
            } catch (exception) {
                next = generator.throw(exception);
            }
        }
        return next.value;
    }

    return [cancelFunction, getPromise()];
}