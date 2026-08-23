class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int> &a, int l, int r) {
        sort(a.begin(), a.end());

        vector<vector<int>> res;
        for (int value = l, i = 0; value <= r; value++) {
            while (i < a.size() && a[i] < value)
                i++;

            if (i < a.size() && a[i] == value)
                i++;
            else if (res.empty() || res.back()[1] + 1 < value)
                res.push_back({ value, value });
            else
                res.back()[1]++;
        }
        return res;
    }
};