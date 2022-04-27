class Solution {
public:
    int mostWordsFound(vector<string> &sentences) {
        int res = 0;
        for (string &sentence : sentences)
            res = max<int>(res, count(sentence.begin(), sentence.end(), ' ') + 1);
        return res;
    }
};