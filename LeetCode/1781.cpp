class Solution {
    int getDiff(vector<int> &a) {
        int minValue = 1e9, maxValue = 0;
        for (int value : a) {
            if (value)
                minValue = min(minValue, value);
            maxValue = max(maxValue, value);
        }
        return maxValue - minValue;
    }
    
public:
    int beautySum(string &s) {        
        int res = 0;
        
        for (int l = 0; l < s.size(); l++) {
            vector<int> count(26);
            for (int r = l; r < s.size(); r++) {
                count[s[r] - 'a']++;
                res += getDiff(count);
            }
        }
        
        return res;
    }
};