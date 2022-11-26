class Solution {
public:
    int bestClosingTime(string &s) {
        int penalty = count(s.begin(), s.end(), 'Y'), resPenalty = penalty, res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            penalty += (s[i] == 'N') - (s[i] == 'Y');
            if (resPenalty > penalty) {
                resPenalty = penalty;
                res = i + 1;
            }
        }
        
        return res;
    }
};