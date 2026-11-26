function sumExcept(a, from, count) {
    if (!Number.isInteger(from) || from < 0)
        from = 0;
    if (!Number.isInteger(count) || count < 0)
        count = 0;

    let sum = 0;
    for (let i = 0; i < a.length; i++)
        if ((i < from || from + count <= i) && Number.isInteger(a[i]))
            sum += a[i];
    return sum;
}

module.exports = sumExcept;