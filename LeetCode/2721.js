async function promiseAll(fs) {
    return new Promise(function(resolve, reject) {
        let res = Array(fs.length);
        let executingCount = fs.length;

        for (let i = 0; i < fs.length; i++) {
            fs[i]().then(function(value) { 
                res[i] = value;
                executingCount--;
                if (!executingCount)
                    resolve(res);
            }).catch(reject);
        }
    });
}