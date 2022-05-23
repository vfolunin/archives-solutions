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
    
    string modify(string &word) {
        static const string VOWELS = "aeiou";
        if (VOWELS.find(tolower(word[0])) == -1)
            rotate(word.begin(), word.begin() + 1, word.end());
        return word + "ma";
    }
    
public:
    string toGoatLatin(string sentence) {
        vector<string> words = split(sentence);
        for (int i = 0; i < words.size(); i++)
            words[i] = modify(words[i]) + string(i + 1, 'a');
        return join(words);
    }
};