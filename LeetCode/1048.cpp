class Solution {
    bool canMakeChain(string &a, string &b) {
        int i = 0;
        while (i < a.size() && a[i] == b[i])
            i++;
        return a.substr(i) == b.substr(i + 1);
    }
    
public:
    int longestStrChain(vector<string> &words) {
        vector<vector<pair<string *, int>>> chain(17);
        for (string &word : words)
            chain[word.size()].push_back({ &word, 1 });
        
        int res = 1;
        for (int i = 1; i < chain.size(); i++) {
            for (auto &[word, chainSize] : chain[i]) {
                for (auto &[prevWord, prevChainSize] : chain[i - 1]) {
                    if (canMakeChain(*prevWord, *word) && chainSize < prevChainSize + 1) {
                        chainSize = prevChainSize + 1;
                        res = max(res, chainSize);
                    }
                }
            }
        }
        return res;
    }
};