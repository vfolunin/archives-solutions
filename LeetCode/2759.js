function jsonParse(s) {
    let i = 0;

    function parseString() {
        let from = ++i;
        while (s[i] != '"')
            i++;
        return s.slice(from, i++);
    }

    function parseNumber() {
        let from = i++;
        while (s[i] == '-' || s[i] == '.' || '0' <= s[i] && s[i] <= '9')
            i++;
        return Number(s.slice(from, i));
    }

    function parseArray() {
        let res = [];
        if (s[++i] == ']') {
            i++;
        } else {
            do {
                res.push(parse());
            } while (s[i++] != ']');
        }
        return res;
    }

    function parseObject() {
        let res = {};
        if (s[++i] == '}') {
            i++;
        } else {
            do {
                let key = parse();
                i++;
                res[key] = parse();
            } while (s[i++] != '}');
        }
        return res;
    }

    function parseLiteral() {
        if (s[i] == 't') {
            i += 4;
            return true;
        } else if (s[i] == 'f') {
            i += 5;
            return false;
        } else {
            i += 4;
            return null;
        }
    }

    function parse() {
        if (s[i] == '"')
            return parseString();
        else if (s[i] == '-' || s[i] == '.' || '0' <= s[i] && s[i] <= '9')
            return parseNumber();
        else if (s[i] == '[')
            return parseArray();
        else if (s[i] == '{')
            return parseObject();
        else
            return parseLiteral();
    }

    return parse();
}