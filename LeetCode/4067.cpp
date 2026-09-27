class Solution {
public:
    int maxSubarray(vector<int> &a) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
        for (auto &[value, p] : pos)
            p.push_back(a.size());

        vector<int> r(a.size(), a.size() - 1);
        int res = 1;
        for (int i = (int)a.size() - 2; i >= 0; i--) {
            r[i] = r[i + 1];
            for (int j = i + 1; j < r[i]; j++) {
                for (int value : { a[i] + a[j], a[i] - a[j], a[j] - a[i] }) {
                    if (auto it = pos.find(value); it != pos.end()) {
                        auto posIt = upper_bound(it->second.begin(), it->second.end(), i);
                        posIt += *posIt == j;
                        r[i] = min(r[i], *posIt - 1);
                    }
                }
            }
            res = max(res, r[i] - i + 1);
        }
        return res;
    }
};