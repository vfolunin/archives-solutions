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
    
    int getMask(string &word) {
        int mask = 0;
        for (char c : word)
            mask |= 1 << (c - 'a');
        return mask;
    }
    
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int broken = getMask(brokenLetters);
        int res = 0;
        for (string &word : split(text))
            res += !(broken & getMask(word));
        return res;
    }
};