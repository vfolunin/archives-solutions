class Solution {
    int compatibility(vector<int> &a, vector<int> &b) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += a[i] == b[i];
        return res;
    }
    
    int compatibility(vector<vector<int>> &a, vector<vector<int>> &b) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += compatibility(a[i], b[i]);
        return res;
    }
    
public:
    int maxCompatibilitySum(vector<vector<int>> &a, vector<vector<int>> &b) {
        sort(a.begin(), a.end());
        int res = 0;
        do {
            res = max(res, compatibility(a, b));
        } while (next_permutation(a.begin(), a.end()));
        return res;
    }
};