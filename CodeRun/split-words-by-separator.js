export function splitWordsBySeparator(words, separator) {
    let res = [];
    for (let word of words)
        for (let part of word.split(separator))
            if (part.length > 0)
                res.push(part);
    return res;
}