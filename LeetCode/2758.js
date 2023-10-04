Date.prototype.nextDay = function() {
    return new Date(this.getTime() + 24 * 60 * 60 * 1000).toISOString().split('T')[0];
}