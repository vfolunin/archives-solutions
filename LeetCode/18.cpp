class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &a, int target) {
        sort(a.begin(), a.end());
        
        set<vector<int>> res;
        
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                for (int l = j + 1, r = a.size() - 1; l < r; l++) {
                    while (l < r && 0LL + a[i] + a[j] + a[l] + a[r] > target)
                        r--;
                    if (l < r && 0LL + a[i] + a[j] + a[l] + a[r] == target)
                        res.insert({ a[i], a[j], a[l], a[r] });
                }
            }
        }
        
        return { res.begin(), res.end() };
    }
};