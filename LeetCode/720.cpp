class Solution {
public:
    string longestWord(vector<string> &words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size() || a.size() == b.size() && a > b;
        });
        
        string res;
        unordered_set<string> buildable;
        for (string &word : words) {
            if (word.size() == 1 || buildable.count(word.substr(0, word.size() - 1))) {
                buildable.insert(word);
                res = word;
            }
        }
        return res;       
    }
};