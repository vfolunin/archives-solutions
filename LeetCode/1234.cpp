class Solution {
public:
    int balancedString(string &s) {
        unordered_map<char, int> count;
        for (char c : s)
            count[c]++;
        
        int need = s.size() / 4;
        if (count['Q'] <= need && count['W'] <= need &&
            count['E'] <= need && count['R'] <= need)
            return 0;
        
        int res = s.size();
        
        for (int l = 0, r = 0; r < s.size(); r++) {
            count[s[r]]--;
            
            while (l <= r &&
                   count['Q'] <= need && count['W'] <= need &&
                   count['E'] <= need && count['R'] <= need) {
                res = min(res, r - l + 1);
                count[s[l]]++;
                l++;
            }
        }
        
        return res;
    }
};