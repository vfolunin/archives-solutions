function flatten(object, keyNamePrefix, flatObject = {}) {
    for (let key in object) {
        let keyName = keyNamePrefix ? keyNamePrefix + '.' + key : key;
        if (typeof object[key] == 'object' && object[key])
            flatten(object[key], keyName, flatObject);
        else
            flatObject[keyName] = object[key];
    }
    return flatObject;
}

function jsonToMatrix(objects) {
    let flatObjects = [];
    for (let object of objects)
        flatObjects.push(flatten(object));

    let keys = [];
    for (let flatObject of flatObjects)
        for (let key in flatObject)
            if (!keys.includes(key))
                keys.push(key);
    keys.sort();
    
    let res = [keys];
    for (let flatObject of flatObjects) {
        let row = [];
        for (let key of keys)
            row.push(key in flatObject ? flatObject[key] : "");
        res.push(row);
    }
    return res;
}