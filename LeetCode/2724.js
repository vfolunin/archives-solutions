function sortBy(a, f) {
    return a.sort(function(lhs, rhs) {
        return f(lhs) - f(rhs);
    });
}