function objDiff(a, b) {
    if (a === b)
        return {};

    if (a === null || b === null ||
        typeof a != "object" || typeof b != "object" ||
        Array.isArray(a) != Array.isArray(b))
        return [a, b];

    let diff = {};
    for (let key in a) {
        if (key in b) {
            let valueDiff = objDiff(a[key], b[key]);
            if (Object.keys(valueDiff).length)
                diff[key] = valueDiff;
        }
    }
    return diff;
}