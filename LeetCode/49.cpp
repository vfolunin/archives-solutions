class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &words) {
        unordered_map<string, vector<string>> anagrams;
        for (string &word : words) {
            string sorted = word;
            sort(sorted.begin(), sorted.end());
            anagrams[sorted].push_back(word);
        }
        
        vector<vector<string>> res;
        for (auto &[_, group] : anagrams)
            res.push_back(group);
        return res;
    }
};