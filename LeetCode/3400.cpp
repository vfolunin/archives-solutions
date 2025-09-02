class Solution {
public:
    int maximumMatchingIndices(vector<int> &a, vector<int> &b) {
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            int cur = 0;
            for (int j = 0; j < a.size(); j++)
                cur += a[(i + j) % a.size()] == b[j];
            res = max(res, cur);
        }
        return res;
    }
};