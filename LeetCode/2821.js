function delayAll(fs, ms) {
    function createPromise(f) {
        return new Promise(function(resolve) {
            setTimeout(function() {
                resolve(f());
            }, ms);
        });
    }

    var res = [];
    for (let f of fs) {
        res.push(function() {
            return createPromise(f);
        });
    }
    return res;
}