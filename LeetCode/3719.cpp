class Solution {
public:
    int longestBalanced(vector<int> &a) {
        int res = 0;

        for (int l = 0; l < a.size(); l++) {
            vector<unordered_set<int>> values(2);
            for (int r = l; r < a.size(); r++) {
                values[a[r] % 2].insert(a[r]);

                if (values[0].size() == values[1].size())
                    res = max(res, r - l + 1);
            }
        }

        return res;
    }
};