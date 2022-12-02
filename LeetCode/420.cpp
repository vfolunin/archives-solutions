class Solution {
public:
    int strongPasswordChecker(string &s) {
        bool hasLower = 0, hasUpper = 0, hasDigit = 0;
        int replaceCount = 0;
        vector<int> count(3);
        
        for (int l = 0, r = 0; l < s.size(); l = r) {
            while (r < s.size() && s[l] == s[r]) {
                hasLower |= islower(s[r]);
                hasUpper |= isupper(s[r]);
                hasDigit |= isdigit(s[r]);
                r++;
            }
            
            replaceCount += (r - l) / 3;
            if (r - l >= 3)
                count[(r - l) % 3]++;
        }
        
        int minOpCount = 3 - hasLower - hasUpper - hasDigit;
        
        if (s.size() < 6)
            return max<int>(minOpCount, 6 - s.size());
        
        if (s.size() <= 20)
            return max(minOpCount, replaceCount);
        
        int deleteCount = s.size() - 20;
        int remainingDeleteCount = deleteCount;
        
        int delta = min(remainingDeleteCount, count[0]);
        remainingDeleteCount -= delta;
        replaceCount -= delta;
        
        delta = min(remainingDeleteCount, count[1] * 2);
        remainingDeleteCount -= delta;
        replaceCount -= delta / 2;

        replaceCount -= remainingDeleteCount / 3;
        
        return deleteCount + max(minOpCount, replaceCount);
    }
};