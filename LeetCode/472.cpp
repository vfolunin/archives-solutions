class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });
        
        unordered_set<string> availableWords;
        vector<string> res;
        
        for (string &word : words) {
            vector<int> can(word.size() + 1);
            can[0] = 1;
            
            for (int r = 1; r <= word.size(); r++)
                for (int l = 1; !can[r] && l <= r; l++)
                    can[r] |= can[l - 1] && availableWords.count(word.substr(l - 1, r - l + 1));
            
            if (can[word.size()])
                res.push_back(word);
            
            availableWords.insert(word);
        }
        
        return res;
    }
};