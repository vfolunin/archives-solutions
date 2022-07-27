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
        string line;
        for (int i = 0; i < words.size(); i++)
            line += words[i] + (i + 1 < words.size() ? " " : "");
        return line;
    }
    
public:
    string arrangeWords(string &line) {
        vector<string> words = split(line);
        words[0][0] = tolower(words[0][0]);
        
        stable_sort(words.begin(), words.end(), [](auto &a, auto &b) {
            return a.size() < b.size();
        });
        words[0][0] = toupper(words[0][0]);
        
        return join(words);
    }
};