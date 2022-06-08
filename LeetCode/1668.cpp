class Solution {
    vector<int> prefixFunction(const string &s) {
        vector<int> p(s.size());
        for (int i = 1; i < s.size(); i++) {
            int border = p[i - 1];
            while (border > 0 && s[i] != s[border])
                border = p[border - 1];
            p[i] = border + (s[i] == s[border]);
        }
        return p;
    }
    
public:
    int maxRepeating(string sequence, string word) {
        string text;
        while (text.size() < sequence.size())
            text += word;
        text += "#";
        text += sequence;
        
        vector<int> p = prefixFunction(text);
        return *max_element(p.begin() + text.find('#'), p.end()) / word.size();
    }
};