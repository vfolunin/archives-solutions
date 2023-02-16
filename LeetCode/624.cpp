class Solution {
public:
    int maxDistance(vector<vector<int>> &a) {
        vector<pair<int, int>> l, r;
        for (int i = 0; i < a.size(); i++) {
            l.push_back({ a[i].front(), i });
            r.push_back({ a[i].back(), i });
        }

        nth_element(l.begin(), l.begin() + 1, l.end());
        nth_element(r.begin(), r.end() - 2, r.end());
        reverse(r.begin(), r.end());

        int res = 0;
        for (int li = 0; li < 2; li++)
            for (int ri = 0; ri < 2; ri++)
                if (l[li].second != r[ri].second)
                    res = max(res, r[ri].first - l[li].first);
        return res;
    }
};