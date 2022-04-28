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

    string join(vector<string> &words) {
        string line;
        for (int i = 0; i < words.size(); i++)
            line += words[i] + (i + 1 < words.size() ? " " : "");
        return line;
    }
    
public:
    string sortSentence(string s) {
        vector<string> words = split(s);
        sort(words.begin(), words.end(), [](auto &a, auto &b) { return a.back() < b.back(); });
        for (string &word : words)
            word.pop_back();
        return join(words);
    }
};