function QueryBatcher(f, ms) {
    this.f = f;
	this.ms = ms;
    this.queries = [];
    this.throttle = 0;
}

QueryBatcher.prototype.getValue = async function(key) {
    let self = this;

    function process() {
        if (self.queries.length) {
            let keys = [];
            for (let query of self.queries)
                keys.push(query.key);

            let queries = self.queries;
            self.f(keys).then(function(results) {
                for (let i = 0; i < results.length; i++)
                    queries[i].resolve(results[i]);
            });
            self.queries = [];

            setTimeout(process, self.ms);
        } else {
            self.throttle = 0;
        }
    }

    if (!this.throttle) {
        this.throttle = 1;
        setTimeout(process, this.ms);
        return new Promise(function(resolve) {
            self.f([key]).then(function(results) {
                resolve(results[0]);
            });
        });
    }

    return new Promise(function(resolve) {
        self.queries.push({ key, resolve });
    });
}