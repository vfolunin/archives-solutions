class Solution {
public:
    int widestPairOfIndices(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> seen = { { 0, -1 } };
        int sum = 0, res = 0;

        for (int i = 0; i < a.size(); i++) {
            sum += a[i] - b[i];
            if (seen.count(sum))
                res = max(res, i - seen[sum]);
            else
                seen[sum] = i;
        }

        return res;
    }
};