class Solution {
public:
    int minSteps(string &a, string &b) {
        vector<int> count(26);
        
        for (char c : a)
            count[c - 'a']++;
        
        for (char c : b)
            count[c - 'a']--;
        
        int res = 0;
        for (int i = 0; i < count.size(); i++)
            res += abs(count[i]);
        
        return res;
    }
};