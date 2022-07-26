class Solution {
public:
    bool canConstruct(string &s, int k) {
        if (k > s.size())
            return 0;
        
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        int oddCount = 0;
        for (int value : count)
            oddCount += value % 2;
        
        return oddCount <= k;
    }
};