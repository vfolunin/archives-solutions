function createChangesNode() {
    return {
        hasValue: 0,
        value: null,
        children: new Map(),
    }
}

function createProxy(obj, changesNode) {
    return new Proxy(obj, {
        set(target, key, value) {
            if (!changesNode.children.has(key))
                changesNode.children.set(key, createChangesNode());
            
            changesNode.children.get(key).hasValue = 1;
            changesNode.children.get(key).value = value;
        },

        get(target, key, value) {
            if (changesNode.hasValue)
                return changesNode.value;
                
            if (!changesNode.children.has(key))
                changesNode.children.set(key, createChangesNode());
            if (changesNode.children.get(key).hasValue)
                return changesNode.children.get(key).value;

            if (typeof obj[key] == 'object' && obj[key] != null)
                return createProxy(obj[key], changesNode.children.get(key));

            return obj[key];
        },
    });
}

function truncate(changesNode) {
    if (changesNode.hasValue)
        return 1;

    let truncated = 0;
    for (let [key, value] of [...changesNode.children]) {
        if (truncate(value))
            truncated = 1;
        else
            changesNode.children.delete(key);
    }
    return truncated;
}
   
function createRes(obj, changesNode) {
    if (changesNode.hasValue)
        return changesNode.value;

    if (!changesNode.children.size)
        return obj;

    let res;
    if (Array.isArray(obj))
        res = [...obj];
    else if (typeof obj == 'object' && obj != null)
        res = {...obj};
    for (let [key, value] of [...changesNode.children])
        res[key] = createRes(obj[key], value);        
    return res;
}

function ImmutableHelper(obj) {
    this.obj = obj;
}

ImmutableHelper.prototype.produce = function(mutator) {    
    let changesNode = createChangesNode();
    let proxy = createProxy(this.obj, changesNode); 
    mutator(proxy);
    truncate(changesNode);
    return createRes(this.obj, changesNode);
};