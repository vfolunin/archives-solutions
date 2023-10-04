function* dateRangeGenerator(start, end, step) {
    let startDate = new Date(start);
    let endDate = new Date(end);
    step *= 24 * 60 * 60 * 1000;

    for (let date = startDate; date <= endDate; date.setTime(date.getTime() + step))
        yield date.toISOString().split('T')[0];
}