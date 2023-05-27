function compactObject(object) {
    if (Array.isArray(object)) {
        let res = [];
        for (let value of object)
            if (value)
                res.push(compactObject(value));
        return res;
    } else if (typeof object == "object") {
        let res = {};
        for (let key in object)
            if (object[key])
                res[key] = compactObject(object[key]);
        return res;
    } else {
        return object;
    }
}