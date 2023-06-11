function join(a, b) {
    let objects = {};

    for (let object of a)
        objects[object.id] = object;
     
    for (let object of b) {
        if (objects[object.id]) {
            for (let key in object)
                objects[object.id][key] = object[key];
        } else {
            objects[object.id] = object;
        }
    }

    return Object.values(objects);
}