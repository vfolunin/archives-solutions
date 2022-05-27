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
    vector<string> findOcurrences(string text, string a, string b) {
        vector<string> words = split(text), res;
        for (int i = 0; i + 2 < words.size(); i++)
            if (words[i] == a && words[i + 1] == b)
                res.push_back(words[i + 2]);
        return res;
    }
};