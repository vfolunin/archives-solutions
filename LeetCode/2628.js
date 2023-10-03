function areDeeplyEqual(a, b) {
    if (a === b)
        return 1;

    if (a === null || b === null ||
        typeof a != "object" || typeof b != "object" ||
        Array.isArray(a) != Array.isArray(b) ||        
        Object.keys(a).length != Object.keys(b).length)
        return 0;
    
    for (let key in a)
        if (!areDeeplyEqual(a[key], b[key]))
            return 0;
    
    return 1;
}