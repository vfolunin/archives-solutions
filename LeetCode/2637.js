function timeLimit(f, ms) {
	return async function(...args) {
        let promise = new Promise(function(resolve, reject) {
            setTimeout(function() {
                reject("Time Limit Exceeded");
            }, ms);
        });

        return Promise.race([f(...args), promise]);
    }
};