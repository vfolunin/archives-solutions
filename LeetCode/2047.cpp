class Solution {
    bool isValid(string &word) {
        int hyphenCount = 0, punctCount = 0;
        for (int i = 0; i < word.size(); i++) {
            if (isdigit(word[i])) {
                return 0;
            } else if (word[i] == '-') {
                hyphenCount++;
                if (hyphenCount > 1 || word.size() == 1 ||
                    i == 0 || !isalpha(word[i - 1]) || i + 1 == word.size() || !isalpha(word[i + 1]))
                    return 0;
            } else if (ispunct(word[i])) {
                punctCount++;
                if (punctCount > 1 || i + 1 < word.size())
                    return 0;
            }
        }
        return 1;
    }
    
public:
    int countValidWords(string sentence) {
        int res = 0;
        
        string word;
        for (char c : sentence) {
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                res += isValid(word);
                word = "";
            }
        }
        if (!word.empty())
            res += isValid(word);
        
        return res;
    }
};