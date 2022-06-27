class Solution {
public:
    bool checkIfCanBreak(string &a, string &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        bool ab = 1, ba = 1;
        for (int i = 0; i < a.size(); i++) {
            ab &= a[i] >= b[i];
            ba &= b[i] >= a[i];
        }
        
        return ab || ba;
    }
};