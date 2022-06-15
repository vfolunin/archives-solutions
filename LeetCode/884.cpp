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
    vector<string> uncommonFromSentences(string a, string b) {
        unordered_map<string, int> count;
        for (string &word : split(a))
            count[word]++;
        for (string &word : split(b))
            count[word]++;
        
        vector<string> res;
        for (auto &[word, count] : count)
            if (count == 1)
                res.push_back(word);
        return res;
    }
};