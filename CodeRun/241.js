function createCountdown(n) {
    if (!Number.isInteger(n) || n < 0)
        n = 0;

    return () => n ? n-- : 0
}

module.exports = createCountdown;