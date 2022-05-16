class Solution {
public:
    int numOfStrings(vector<string> &patterns, string word) {
        int res = 0;
        for (string &pattern : patterns)
            res += word.find(pattern) != -1;
        return res;
    }
};