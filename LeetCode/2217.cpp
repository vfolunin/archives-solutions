class Solution {
public:
    vector<long long> kthPalindrome(vector<int> &queries, int size) {
        int half = (size + 1) / 2;
        
        long long from = 1;
        for (int i = 0; i < half - 1; i++)
            from *= 10;
        
        vector<long long> res(queries.size(), -1);
        for (int i = 0; i < queries.size(); i++) {
            if (from + queries[i] - 1 < from * 10) {
                string l = to_string(from + queries[i] - 1);
                string r = l;
                if (size % 2)
                    r.pop_back();
                reverse(r.begin(), r.end());
                res[i] = stoll(l + r);
            }
        }
        return res;
    }
};