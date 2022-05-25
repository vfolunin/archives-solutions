class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        
        vector<pair<int, int>> last = { { -1, -1 } };
        for (vector<int> &envelope : envelopes) {
            int l = 0, r = last.size();
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (last[m].first < envelope[0] && last[m].second < envelope[1])
                    l = m;
                else
                    r = m;
            }
            if (r == last.size())
                last.emplace_back();
            last[r] = { envelope[0], envelope[1] };
        }
        
        return last.size() - 1;
    }
};