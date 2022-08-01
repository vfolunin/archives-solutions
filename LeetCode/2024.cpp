class Solution {
public:
    int maxConsecutiveAnswers(string &s, int k) {
        int res = 0;
        
        for (char symbol : { 'T', 'F' }) {
            int count = 0;
            for (int l = 0, r = 0; r < s.size(); r++) {
                count += s[r] == symbol;
                while (count > k) {
                    count -= s[l] == symbol;
                    l++;
                }
                res = max(res, r - l + 1);
            }
        }
        
        return res;
    }
};