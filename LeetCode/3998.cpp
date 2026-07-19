class Solution {
    void restoreQuery(string &query, int count0) {
        count0 -= count(query.begin(), query.end(), '0');
        for (char &c : query) {
            if (c == '?') {
                if (count0) {
                    c = '0';
                    count0--;
                } else {
                    c = '1';
                }
            }
        }
    }

    bool checkQuery(string &s, string &query) {
        int balance = 0;
        for (int i = 0; i < s.size(); i++) {
            balance += s[i] - query[i];
            if (balance < 0)
                return 0;
        }
        return !balance;
    }

public:
    vector<bool> transformStr(string &s, vector<string> &queries) {
        int count0 = count(s.begin(), s.end(), '0');
        for (string &query : queries)
            restoreQuery(query, count0);
        
        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
            res[i] = checkQuery(s, queries[i]);
        return res;
    }
};