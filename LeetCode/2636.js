async function promisePool(functions, executingLimit) {
    return new Promise(function(resolve) {
        let index = 0, executingCount = 0;
        
        function execute() {
            while (index < functions.length && executingCount < executingLimit) {
                executingCount++;
                functions[index++]().then(function() {
                    executingCount--;
                    execute();
                });
            }
            if (index == functions.length && !executingCount)
                resolve();
        }

        execute();
    });
}