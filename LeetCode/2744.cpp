class Solution {
public:
    int maximumNumberOfStringPairs(vector<string> &words) {
        multiset<string> wordSet = { words.begin(), words.end() };
        int res = 0;
        
        while (!wordSet.empty()) {
            auto word = *wordSet.begin();
            wordSet.erase(wordSet.begin());

            reverse(word.begin(), word.end());

            if (auto it = wordSet.find(word); it != wordSet.end()) {
                res++;
                wordSet.erase(it);
            }
        }
        
        return res;
    }
};