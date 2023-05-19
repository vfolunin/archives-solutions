class EventEmitter {
	constructor() {
		this.callbacks = {};
	}

	subscribe(event, callback) {
		if (!this.callbacks[event])
			this.callbacks[event] = [];
		this.callbacks[event].push(callback);

        return {
            unsubscribe: () => {
                this.callbacks[event].splice(this.callbacks[event].indexOf(callback), 1);
            }
        };
	}

	emit(event, args = []) {
        let result = [];
        if (this.callbacks[event])
		    for (let callback of this.callbacks[event])
                result.push(callback(...args));
        return result;
	}
}