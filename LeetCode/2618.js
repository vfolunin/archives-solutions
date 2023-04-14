function checkIfInstanceOf(obj, classFunction) {
    if (obj == null)
        return false;
    if (obj.constructor === classFunction)
        return true;
    return checkIfInstanceOf(Object.getPrototypeOf(obj), classFunction);
}