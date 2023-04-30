function* inorderTraversal(a) {
    for (let value of a) {
        if (Array.isArray(value))
            yield* inorderTraversal(value);
        else
            yield value;
    }
}