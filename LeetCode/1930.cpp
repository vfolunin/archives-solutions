class Solution {
public:
    int countPalindromicSubsequence(string &s) {
        vector<int> countL(26), countR(26);
        for (char c : s)
            countR[c - 'a']++;
        
        unordered_set<int> res;
        
        for (int i = 0; i < s.size(); i++) {
            countR[s[i] - 'a']--;
            
            for (int j = 0; j < countL.size(); j++)
                if (countL[j] && countR[j])
                    res.insert(j * 100 + s[i] - 'a');
            
            countL[s[i] - 'a']++;
        }
        
        return res.size();
    }
};