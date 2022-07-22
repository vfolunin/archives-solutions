class Solution {
public:
    int numTimesAllBlue(vector<int> &a) {
        int maxValue = 0, res = 0;
        
        for (int i = 0; i < a.size(); i++) {
            maxValue = max(maxValue, a[i]);
            res += maxValue == i + 1;
        }
        
        return res;
    }
};