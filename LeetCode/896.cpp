class Solution {
public:
    bool isMonotonic(vector<int> &a) {
        if (a.size() == 1)
            return 1;
        
        vector<int> flags(2);
        for (int i = 0; i + 1 < a.size(); i++) {
            flags[0] |= a[i] < a[i + 1];
            flags[1] |= a[i] > a[i + 1];
        }
        
        return !flags[0] || !flags[1];
    }
};