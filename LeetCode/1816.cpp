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
    string truncateSentence(string s, int k) {
        vector<string> words = split(s);
        words.resize(k);
        return join(words);
    }
};