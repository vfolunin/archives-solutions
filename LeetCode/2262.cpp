class Solution {
public:
    long long appealSum(string &s) {
        vector<int> last(26, -1);        
        long long delta = 0, res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            delta += i - last[s[i] - 'a'];
            res += delta;
            last[s[i] - 'a'] = i;
        }
        
        return res;
    }
};