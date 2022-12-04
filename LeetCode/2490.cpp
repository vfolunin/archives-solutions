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
    bool isCircularSentence(string &line) {
        vector<string> words = split(line);
        for (int i = 0; i + 1 < words.size(); i++)
            if (words[i].back() != words[i + 1].front())
                return 0;
        return words.back().back() == words.front().front();
    }
};