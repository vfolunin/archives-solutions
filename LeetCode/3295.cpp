class Solution {
public:
    bool reportSpam(vector<string> &message, vector<string> &bannedWords) {
        unordered_set<string> banned(bannedWords.begin(), bannedWords.end());
        int bannedCount = 0;

        for (string &word : message)
            bannedCount += banned.count(word);
        
        return bannedCount >= 2;
    }
};