class Solution {
public:
    bool maxSubstringLength(string &s, int k) {
        if (!k)
            return 1;
            
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++)
            pos[s[i] - 'a'].push_back(i);

        vector<pair<int, int>> segments;
        for (vector<int> &a : pos) {
            if (a.empty())
                continue;
            
            int l = a.front(), r = a.back();
            while (1) {
                bool updated = 0;
                for (vector<int> &b : pos) {
                    auto it = lower_bound(b.begin(), b.end(), l);
                    if (it != b.end() && *it <= r && (b.front() < l || r < b.back())) {
                        l = min(l, b.front());
                        r = max(r, b.back());
                        updated = 1;
                    }
                }
                if (!updated)
                    break;
            }

            if (l || r + 1 < s.size())
                segments.push_back({ l, r });
        }

        sort(segments.begin(), segments.end(), [](auto &lhs, auto &rhs) {
            return lhs.second < rhs.second;
        });

        vector<int> count(segments.size(), 1);
        for (int i = 1; i < segments.size(); i++)
            for (int j = 0; j < i; j++)
                if (segments[j].second < segments[i].first)
                    count[i] = max(count[i], count[j] + 1);
        return !count.empty() && *max_element(count.begin(), count.end()) >= k;
    }
};