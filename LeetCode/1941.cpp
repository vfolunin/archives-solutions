class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        int commonCount = 0;
        for (int count : count) {
            if (!count)
                continue;
            if (!commonCount)
                commonCount = count;
            if (count != commonCount)
                return 0;
        }
        
        return 1;
    }
};