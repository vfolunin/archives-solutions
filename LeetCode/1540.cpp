class Solution {
public:
    bool canConvertString(string &a, string &b, int maxShift) {
        if (a.size() != b.size())
            return 0;
        
        vector<int> nextShift(26);
        iota(nextShift.begin(), nextShift.end(), 0);
        
        for (int i = 0; i < a.size(); i++) {
            int shift = b[i] - a[i];
            if (shift < 0)
                shift += 26;
            
            if (!shift)
                continue;
            
            if (nextShift[shift] > maxShift)
                return 0;
            
            nextShift[shift] += 26;
        }
        
        return 1;
    }
};