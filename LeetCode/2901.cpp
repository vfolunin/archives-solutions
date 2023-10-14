class Solution {
    int diff(string &a, string &b) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += a[i] != b[i];
        return res;
    }
    
public:
    vector<string> getWordsInLongestSubsequence(int size, vector<string> &words, vector<int> &a) {       
        vector<int> len(size, 1), from(size, -1);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] != a[j] && words[i].size() == words[j].size() && diff(words[i], words[j]) == 1 && len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    from[i] = j;
                }
            }
        }
        
        vector<string> res;
        for (int i = max_element(len.begin(), len.end()) - len.begin(); i != -1; i = from[i])
            res.push_back(words[i]);
        reverse(res.begin(), res.end());
        return res;
    }
};