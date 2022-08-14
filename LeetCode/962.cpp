class Solution {
public:
    int maxWidthRamp(vector<int> &a) {
        int res = 0;
        vector<int> values, indexes;
        
        for (int i = 0; i < a.size(); i++) {
            if (values.empty() || values.back() > a[i]) {
                values.push_back(a[i]);
                indexes.push_back(i);
            } else {
                int pos = lower_bound(values.begin(), values.end(), a[i], greater<int>()) - values.begin();
                res = max(res, i - indexes[pos]);
            }
        }
        
        return res;
    }
};