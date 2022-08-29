class Solution {
    bool isSubstring(string &a, string &b) {
        int bi = 0;
        for (int ai = 0; ai < a.size() && bi < b.size(); ai++)
            bi += a[ai] == b[bi];
        return bi == b.size();
    }
    
public:
    int findLUSlength(vector<string> &words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() > b.size();
        });
        
        unordered_map<string, int> count;
        for (int i = 0; i < words.size(); i++) {
            bool ok = 1;
            for (int j = 0; ok && j < i; j++)
                ok &= words[i].size() == words[j].size() || !isSubstring(words[j], words[i]);
            
            if (ok)
                count[words[i]]++;
        }
        
        int res = -1;
        
        for (auto &[word, count] : count)
            if (count == 1)
                res = max<int>(res, word.size());
        
        return res;
    }
};