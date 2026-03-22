module.exports = function(size, a, limit) {
    let count = [];
    for (let i = 0; i <= 25; i++)
        count.push(0);
    
    for (let value of a)
        count[value]++;
    
    let res = 0;
    for (let value = count.length - 1; value >= 0; value--) {
        let delta = Math.min(count[value], limit);
        res += delta * value;
        limit -= delta;
    }
    return res;
}