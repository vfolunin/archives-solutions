class Solution {
public:
    vector<string> shortestSubstrings(vector<string> &a) {
        vector<string> res(a.size());

        for (int i = 0; i < a.size(); i++) {
            for (int len = 1; len <= a[i].size(); len++) {
                for (int from = 0; from + len <= a[i].size(); from++) {
                    string candidate = a[i].substr(from, len);
                    bool ok = 1;

                    for (int j = 0; j < a.size(); j++)
                        ok &= i == j || a[j].find(candidate) == -1;
                    
                    if (ok && (res[i].empty() || res[i] > candidate))
                        res[i] = candidate;
                }

                if (!res[i].empty())
                    break;
            }
        }

        return res;
    }
};