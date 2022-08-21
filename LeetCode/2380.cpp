class Solution {
public:
    int secondsToRemoveOccurrences(string &s) {
        for (int i = 0; 1; i++) {
            string nextS = s;
            
            for (int j = 1; j < s.size(); j++)
                if (s[j - 1] == '0' && s[j] == '1')
                    swap(nextS[j - 1], nextS[j]);
            
            if (s != nextS)
                s.swap(nextS);
            else
                return i;
        }
    }
};