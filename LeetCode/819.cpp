class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> count;
        int maxCount = 0;
        string maxWord, word;
        
        for (char c : paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            } else if (!word.empty()) {
                if (!bannedSet.count(word) && maxCount < ++count[word]) {
                    maxCount = count[word];
                    maxWord = word;
                }
                word = "";
            }
        }
        if (!word.empty() && !bannedSet.count(word) && maxCount < ++count[word]) {
            maxCount = count[word];
            maxWord = word;
        }
        
        return maxWord;
    }
};