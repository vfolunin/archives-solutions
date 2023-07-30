class Solution {
    bool isBetter(const string &a, const string &b) {
        return a.size() > b.size() || a.size() == b.size() && a > b;
    }

    string combine(const string &a, const string &b) {
        string res = a + b;

        for (int offset = 1; offset <= b.size(); offset++) {
            string cur = a + b.substr(offset);
            if (cur.find(b) != -1 && isBetter(res, cur))
                res = cur;
        }

        return res;
    }

public:
    string minimumString(string &a, string &b, string &c) {
        vector<string> words = { a, b, c };
        sort(words.begin(), words.end());

        string res = a + b + c;

        do {
            string cur = combine(combine(words[0], words[1]), words[2]);
            if (isBetter(res, cur))
                res = cur;
        } while (next_permutation(words.begin(), words.end()));

        return res;
    }
};