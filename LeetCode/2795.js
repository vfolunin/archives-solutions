function promiseAllSettled(fs) {
    return new Promise(function(resolve) {
        if (!fs.length) {
            resolve([]);
            return;
        }

        let results = new Array(fs.length);
        let resultCount = 0;

        fs.forEach(async function(f, index) {
            try {
                let result = await f();
                results[index] = { status: 'fulfilled', value: result };
            } catch (error) {
                results[index] = { status: 'rejected', reason: error };
            } finally {
                if (++resultCount == fs.length)
                    resolve(results);
            }
        });
    });
}