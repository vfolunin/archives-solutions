class Solution {
public:
    vector<long long> countKConstraintSubstrings(string &s, int limit, vector<vector<int>> &queries) {
        vector<int> count(2);
        vector<int> from(s.size());

        for (int l = 0, r = 0; r < s.size(); r++) {
            count[s[r] - '0']++;
            while (count[0] > limit && count[1] > limit) {
                count[s[l] - '0']--;
                l++;
            }
            from[r] = l;
        }

        vector<long long> pLen(from.size());
        for (int i = 0; i < pLen.size(); i++)
            pLen[i] = i - from[i] + 1 + (i ? pLen[i - 1] : 0);

        vector<long long> res;
        for(vector<int> &query : queries) {
            int l = query[0] - 1, r = query[1] + 1;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (from[m] < query[0])
                    l = m;
                else
                    r = m;
            }
    
            long long cur = (r - query[0]) * (r - query[0] + 1LL) / 2;
            if (r <= query[1])
                cur += pLen[query[1]] - (r ? pLen[r - 1] : 0);
            
            res.push_back(cur);
        }

        return res;
    }
};