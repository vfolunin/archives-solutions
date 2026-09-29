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
    char kthCharacter(string line, long long index) {
        vector<string> words = split(line);

        for (string &word : words) {
            for (int i = 0; i < word.size(); i++) {
                if (index <= i)
                    return word[i];
                index -= i + 1;
            }
            if (!index)
                return ' ';
            index--;
        }

        return '#';
    }
};