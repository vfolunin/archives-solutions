class Solution {
    vector<string> split(string &line) {
        vector<string> words;
        string word;
        for (char c : line) {
            if (c != ' ') {
                word += c;
            } else {
                words.push_back(word);
                word.clear();
            }
        }
        words.push_back(word);
        return words;
    }
    
public:
    bool wordPattern(string a, string s) {
        vector<string> b = split(s);
        if (a.size() != b.size())
            return 0;
        
        unordered_map<char, string> ab;
        unordered_map<string, char> ba;
        
        for (int i = 0; i < a.size(); i++) {
            if (!ab.count(a[i]) && !ba.count(b[i])) {
                ab[a[i]] = b[i];
                ba[b[i]] = a[i];
            } else if (ab[a[i]] != b[i] || ba[b[i]] != a[i]) {
                return 0;
            }
        }
        
        return 1;
    }
};