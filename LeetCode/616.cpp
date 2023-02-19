class Solution {
public:
    string addBoldTag(string &s, vector<string> &words) {
        vector<int> marked(s.size());
        for (string &word : words)
            for (int from = s.find(word, 0); from != -1; from = s.find(word, from + 1)) 
                fill(marked.begin() + from, marked.begin() + from + word.size(), 1);
        
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (marked[i] && (!i || !marked[i - 1]))
                res += "<b>";
            res += s[i];
            if (marked[i] && (i + 1 == s.size() || !marked[i + 1]))
                res += "</b>";
        }
        return res;
    }
};