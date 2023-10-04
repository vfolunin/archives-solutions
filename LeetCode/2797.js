function partial(f, args) {
    return function(...restArgs) {
        let ri = 0;
        for (let i = 0; i < args.length; i++)
            if (args[i] == '_')
                args[i] = restArgs[ri++];
        
        args = args.concat(restArgs.slice(ri));
        
        return f(...args);
    };
}