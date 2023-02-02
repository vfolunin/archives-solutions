class Solution {
public:
    vector<string> findMissingRanges(vector<int> &a, int l, int r) {
        vector<pair<int, int>> segments;

        if (a.empty()) {
            segments.push_back({ l, r });
        } else {
            if (l < a[0])
                segments.push_back({ l, a[0] - 1 });

            for (int i = 0; i + 1 < a.size(); i++)
                if (a[i] + 1 < a[i + 1])
                    segments.push_back({ a[i] + 1, a[i + 1] - 1 });
            
            if (a.back() < r)
                segments.push_back({ a.back() + 1, r });
        }

        vector<string> res;
        for (auto &[l, r] : segments) {
            res.push_back(to_string(l));
            if (l < r)
                res.back() += "->" + to_string(r);
        }
        return res;
    }
};