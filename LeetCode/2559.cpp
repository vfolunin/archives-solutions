class Solution {
    bool isGood(string &s) {
        static const string VOWELS = "aeiou";
        return VOWELS.find(s.front()) != -1 && VOWELS.find(s.back()) != -1;
    }

    int getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }

public:
    vector<int> vowelStrings(vector<string> &a, vector<vector<int>> &queries) {
        vector<int> p(a.size());
        for (int i = 0; i < a.size(); i++)
            p[i] = isGood(a[i]);        
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
            res[i] = getSum(p, queries[i][0], queries[i][1]);
        return res;
    }
};