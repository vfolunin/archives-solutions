class Solution {
    int solve(string &s, char a, char b) {
        int res = 0, aCount = 0, bCount = 0, restarted = 0;
        
        for (char c : s) {
            aCount += c == a;
            bCount += c == b;
            
            if (aCount)
                res = max(res, bCount - aCount);
            else if (restarted)
                res = max(res, bCount - 1);
            
            if (aCount > bCount) {
                aCount = bCount = 0;
                restarted = 1;
            }
        }
        
        return res;
    }
    
public:
    int largestVariance(string &s) {
        int res = 0;
        
        for (char a = 'a'; a <= 'z'; a++)
            for (char b = 'a'; b <= 'z'; b++)
                res = max(res, solve(s, a, b));
        
        return res;
    }
};