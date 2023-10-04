function promisify(f) {
     return async function(...args) {
        return new Promise(function(resolve, reject) {
            let handler = function(value, error) {
                if (error)
                    reject(error);
                else
                    resolve(value);
            };

            f(handler, ...args);
        });
    };
}