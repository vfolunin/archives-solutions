class Solution {
public:
    int maxPalindromesAfterOperations(vector<string> &a) {
        vector<int> letterCount(26);
        for (string &s : a)
            for (char c : s)
                letterCount[c - 'a']++;
        
        int pairCount = 0;
        for (int count : letterCount)
            pairCount += count / 2;
        
        sort(a.begin(), a.end(), [](string &lhs, string &rhs) {
            return lhs.size() < rhs.size();
        });

        int res = 0;
        for (string &s : a) {
            int pairNeeded = s.size() / 2;
            if (pairCount >= pairNeeded) {
                pairCount -= pairNeeded;
                res++;
            } else {
                break;
            }
        }
        return res;
    }
};