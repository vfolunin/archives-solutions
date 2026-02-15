class Solution {
public:
    int prefixConnected(vector<string> &words, int prefixSize) {
        unordered_map<string, int> count;
        for (string &word : words)
            if (word.size() >= prefixSize)
                count[word.substr(0, prefixSize)]++;
        
        int res = 0;
        for (auto &[_, count] : count)
            res += count > 1;
        return res;
    }
};