class Solution {
public:
    int shortestDistance(vector<string> &words, string &a, string &b) {
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