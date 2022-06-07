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
    string reorderSpaces(string text) {
        vector<string> words = split(text);
        
        int spaceCount = text.size();
        for (string &word : words)
            spaceCount -= word.size();
        
        if (words.size() == 1)
            return words[0] + string(spaceCount, ' ');
        
        string res;
        for (int i = 0; i + 1 < words.size(); i++)
            res += words[i] + string(spaceCount / (words.size() - 1), ' ');
        res += words.back() + string(spaceCount % (words.size() - 1), ' ');
        
        return res;
    }
};