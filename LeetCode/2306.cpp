class Solution {
public:
    long long distinctNames(vector<string> &words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        vector<vector<int>> wordCount(26, vector<int>(26));
        
        for (string &word : words) {
            char first = word[0];
            for (word[0] = 'a'; word[0] <= 'z'; word[0]++)
                if (word[0] != first && !wordSet.count(word))
                    wordCount[first - 'a'][word[0] - 'a']++;
            word[0] = first;
        }
        
        long long res = 0;
        
        for (string &word : words) {
            char first = word[0];
            for (word[0] = 'a'; word[0] <= 'z'; word[0]++)
                if (word[0] != first && !wordSet.count(word))
                    res += wordCount[word[0] - 'a'][first - 'a'];
            word[0] = first;
        }
        
        return res;
    }
};