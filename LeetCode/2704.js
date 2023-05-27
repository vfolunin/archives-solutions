function expect(value) {
    return {
        toBe(otherValue) {
            if (value === otherValue)
                return true;
            throw "Not Equal";
        },
        notToBe(otherValue) {
            if (value !== otherValue)
                return true;
            throw "Equal";
        }
    };
}