
class Solution {
    set<string> merge(const set<string> &a, const set<string> &b) {
        set<string> res = a;
        res.insert(b.begin(), b.end());
        return res;
    }

    set<string> combine(const set<string> &a, const set<string> &b) {
        set<string> res;
        for (const string &sa : a)
            for (const string &sb : b)
                res.insert(sa + sb);
        return res;
    }

    set<string> parseLetter(stringstream &ss) {
        char c = ss.get();
        return { string(1, c) };
    }

    set<string> parseBrackets(stringstream &ss) {
        set<string> res;
        do {
            ss.get();
            res = merge(res, parse(ss));
        } while (ss.peek() == ',');
        ss.get();
        return res;
    }

    set<string> parse(stringstream &ss) {
        set<string> res = { "" };
        while (ss.peek() != ',' && ss.peek() != '}' && ss.peek() != EOF) {
            if (isalpha(ss.peek()))
                res = combine(res, parseLetter(ss));
            else
                res = combine(res, parseBrackets(ss));
        }
        return res;
    }

public:
    vector<string> braceExpansionII(string &s) {
        stringstream ss(s);
        set<string> res = parse(ss);
        return { res.begin(), res.end() };
    }
};