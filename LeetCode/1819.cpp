class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int> &a) {
        vector<int> has(2e5 + 1);
        for (int value : a)
            has[value] = 1;
        
        int res = 0;
        
        for (int i = 1; i <= 2e5; i++) {
            for (int j = i, d = 0; j <= 2e5; j += i) {
                if (has[j]) {
                    d = gcd(d, j);
                    
                    if (d == i) {
                        res++;
                        break;
                    }
                }
            }
        }
        
        return res;
    }
};