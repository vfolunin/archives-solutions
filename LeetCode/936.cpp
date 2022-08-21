class Solution {
    bool fits(string &s, int from, string &pattern) {
        int questionCount = 0;
        for (int i = 0; i < pattern.size(); i++) {
            if (s[from + i] == '?')
                questionCount++;
            else if (s[from + i] != pattern[i])
                return 0;
        }
        return questionCount < pattern.size();
    }
    
public:
    vector<int> movesToStamp(string &stamp, string &target) {
        vector<int> res;
        
        while (1) {
            bool updated = 0;
            
            for (int i = 0; i + stamp.size() <= target.size(); i++) {
                if (fits(target, i, stamp)) {
                    res.push_back(i);
                    fill(target.begin() + i, target.begin() + i + stamp.size(), '?');
                    updated = 1;
                    break;
                }
            }
            
            if (!updated)
                break;
        }
        
        if (count(target.begin(), target.end(), '?') == target.size()) {
            reverse(res.begin(), res.end());
            return res;
        } else {
            return {};
        }            
    }
};