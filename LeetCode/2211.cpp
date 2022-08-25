class Solution {
public:
    int countCollisions(string &s) {
        int res = 0;
        int right = 0;
        
        for (char c : s) {
            if (c == 'L') {
                if (right == -1) {
                    res++;
                } else if (right > 0) {
                    res += right + 1;
                    right = -1;
                }
            } else if (c == 'S') {
                if (right > 0)
                    res += right;
                right = -1;
            } else {
                if (right <= 0)
                    right = 1;
                else
                    right++;
            }
        }
        
        return res;
    }
};