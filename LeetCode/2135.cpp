class Solution {
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords) {
        unordered_set<string> canMake;
        
        for (string &word : startWords) {
            sort(word.begin(), word.end());
            for (word += 'a'; word.back() <= 'z'; word.back()++) {
                if (!binary_search(word.begin(), word.end() - 1, word.back())) {
                    string sortedWord = word;
                    sort(sortedWord.begin(), sortedWord.end());
                    canMake.insert(sortedWord);
                }
            }
        }
        
        int res = 0;
        
        for (string &word : targetWords) {   
            sort(word.begin(), word.end());
            res += canMake.count(word);
        }
        
        return res;
    }
};