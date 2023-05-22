function jsonStringify(object) {
    if (object === null)
        return "null";

    if (typeof object == "string")
        return `"${object}"`;

    if (Array.isArray(object)) {
        let a = [];
        for (let value of object)
            a.push(jsonStringify(value));
        return `[${a.join(",")}]`;
    }

    if (typeof object == "object") {
        let a = [];
        for (let key in object)
            a.push(`"${key}":${jsonStringify(object[key])}`);
        return `{${a.join(",")}}`;
    }

    return String(object);
};