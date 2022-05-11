class Solution {
public:
    string sortString(string s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        string res;
        while (res.size() < s.size()) {
            for (int i = 0; i < 26; i++) {
                if (count[i]) {
                    res += 'a' + i;
                    count[i]--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (count[i]) {
                    res += 'a' + i;
                    count[i]--;
                }
            }
        }
        return res;
    }
};