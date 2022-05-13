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
    
    string join(vector<string> &words) {
        string res;
        for (string &word : words)
            res += (res.empty() ? "" : " ") + word;
        return res;
    }
    
public:
    string reverseWords(string s) {
        vector<string> words = split(s);
        reverse(words.begin(), words.end());
        return join(words);
    }
};