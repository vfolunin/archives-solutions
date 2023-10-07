function undefinedToNull(obj) {
    for (let key in obj) {
        if (obj[key] == undefined)
            obj[key] = null;
        else if (typeof obj[key] == 'object')
            obj[key] = undefinedToNull(obj[key]);
    }
    return obj;
}