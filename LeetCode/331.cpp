class Solution {
    vector<string> split(string &line, const string &separators) {
        vector<string> words;
        string word;
        for (char c : line) {
            if (separators.find(c) == -1) {
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
    
    int check(vector<string> &tokens, int i) {
        if (i >= tokens.size())
            return 0;
        
        if (tokens[i] == "#")
            return i + 1;
        
        int lTo = check(tokens, i + 1);
        return lTo ? check(tokens, lTo) : 0;
    }
    
public:
    bool isValidSerialization(string &preorder) {
        vector<string> tokens = split(preorder, ",");
        return check(tokens, 0) == tokens.size();
    }
};