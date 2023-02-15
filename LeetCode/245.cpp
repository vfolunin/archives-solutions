class Solution {
    int shortestWordDistance(vector<string> &words, string &s) {
        int last = -1, res = 1e9;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == s) {
                if (last != -1)
                    res = min(res, i - last);
                last = i;
            }
        }
        return res;
    }

public:
    int shortestWordDistance(vector<string> &words, string &a, string &b) {
        if (a == b)
            return shortestWordDistance(words, a);
            
        int aLast = -1, bLast = -1, res = 1e9;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == a) {
                if (bLast != -1)
                    res = min(res, i - bLast);
                aLast = i;
            } else if (words[i] == b) {
                if (aLast != -1)
                    res = min(res, i - aLast);
                bLast = i;
            }
        }
        return res;
    }
};