class Solution {
public:
    long long minimumSteps(string &s) {
        long long res = 0;
        int ones = 0;

        for (char c : s) {
            if (c == '0')
                res += ones;
            else
                ones++;
        }
        
        return res;
    }
};