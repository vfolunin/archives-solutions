class Solution {
public:
    vector<vector<int>> divideArray(vector<int> &a, int diff) {
        sort(a.begin(), a.end());

        vector<vector<int>> res;
        for (int i = 0; i < a.size(); i += 3) {
            if (a[i] + diff < a[i + 2])
                return {};
            res.push_back({ a[i], a[i + 1], a[i + 2] });
        }

        return res;
    }
};