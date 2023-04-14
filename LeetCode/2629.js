function compose(fs) {
    return function(value) {
        let res = value;
        for (let i = fs.length - 1; i >= 0; i--)
            res = fs[i](res);
        return res;
    };
};