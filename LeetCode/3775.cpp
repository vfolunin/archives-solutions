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

    int getVowelCount(string &s) {
        string vowels = "aeiou";
        int res = 0;
        for (char c : s)
            res += vowels.find(c) != -1;
        return res;
    }

public:
    string reverseWords(string &line) {
        vector<string> words = split(line);
        int vowelCount = getVowelCount(words[0]);
        for (int i = 1; i < words.size(); i++)
            if (getVowelCount(words[i]) == vowelCount)
                reverse(words[i].begin(), words[i].end());
        return join(words);
    }
};