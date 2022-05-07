class Solution {
public:
    bool checkRecord(string s) {
        int aCount = 0, lRow = 0;
        
        for (char c : s) {
            if (c == 'A')
                if (++aCount > 1)
                    return 0;
            
            if (c == 'L') {
                if (++lRow > 2)
                    return 0;
            } else {
                lRow = 0;
            }
        }
        
        return 1;
    }
};