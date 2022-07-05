class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> res;
        
        for (int l = 0; l < digits.size(); l++) {
            int value = 0;
            for (int r = l; r < digits.size(); r++) {
                value = value * 10 + digits[r] - '0';
                if (low <= value && value <= high)
                    res.push_back(value);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};