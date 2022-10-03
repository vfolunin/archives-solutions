class Solution {
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles) {
        unordered_map<int, int> wordCount;
        for (string &word : words) {
            int mask = 0;
            for (char c : word)
                mask |= 1 << (c - 'a');
            wordCount[mask]++;
        }
        
        vector<int> res(puzzles.size());
        for (int i = 0; i < res.size(); i++) {
            int first = 1 << (puzzles[i][0] - 'a'), mask = 0;
            for (char c : puzzles[i].substr(1))
                mask |= 1 << (c - 'a');
            
            res[i] += wordCount[first];
            for (int submask = mask; submask; submask = mask & (submask - 1))
                res[i] += wordCount[submask | first];
        }
        return res;
    }
};