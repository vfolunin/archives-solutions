class Solution {
public:
    int maxXorSubsequences(vector<int> &a) {
        int res = 0;
        while (1) {
            int maxValue = *max_element(a.begin(), a.end());
            if (!maxValue)
                break;
            
            res = max(res, res ^ maxValue);

            for (int &value : a)
                value = min(value, value ^ maxValue);
        }
        return res;
    }
};