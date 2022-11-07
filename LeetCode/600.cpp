class Solution {
public:
    int findIntegers(int n) {
        vector<int> count = { 1, 2 };
        for (int len = 2; len < 30; len++)
            count.push_back(count[len - 1] + count[len - 2]);
        
        int res = 1;
        for (int bit = 29; bit >= 0; bit--) {
            if (n & (1 << bit)) {
                res += count[bit];
                if (n & (1 << (bit + 1))) {
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};