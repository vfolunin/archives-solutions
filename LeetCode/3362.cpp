class Solution {
public:
    int maxRemoval(vector<int> &a, vector<vector<int>> &queries) {
        sort(queries.begin(), queries.end());
        
        vector<int> delta(a.size() + 1);
        int sum = 0;
        multiset<int> tos;
        int res = queries.size();

        for (int ai = 0, qi = 0; ai < a.size(); ai++) {
            sum += delta[ai];

            while (!tos.empty() && *tos.begin() < ai)
                tos.erase(tos.begin());
            for ( ; qi < queries.size() && queries[qi][0] == ai; qi++)
                tos.insert(queries[qi][1]);
            
            while (sum < a[ai] && !tos.empty()) {
                sum++;
                delta[*prev(tos.end()) + 1] -= 1;
                tos.erase(prev(tos.end()));
                res--;
            }
            if (sum < a[ai])
                return -1;
        }

        return res;
    }
};