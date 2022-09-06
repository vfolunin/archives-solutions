class Solution {
    vector<string> split(string &line) {
        vector<string> words;
        string word;
        for (char c : line) {
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty())
            words.push_back(word);
        return words;
    }

public:
    bool areSentencesSimilar(string &sa, string &sb) {
        vector<string> a = split(sa), b = split(sb);
        
        int l = 0;
        while (l < a.size() && l < b.size() && a[l] == b[l])
            l++;
        
        int r = 0;
        while (r < a.size() && r < b.size() && a[a.size() - 1 - r] == b[b.size() - 1 - r])
            r++;
        
        return l + r >= min(a.size(), b.size());
    }
};