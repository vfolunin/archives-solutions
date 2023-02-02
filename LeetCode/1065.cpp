class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string> &words) {
        vector<vector<int>> res;
        for (int i = 0; i < text.size(); i++)
            for (string &word : words)
                if (i + word.size() <= text.size() && !text.compare(i, word.size(), word))
                    res.push_back({ i, i + (int)word.size() - 1 });
            
        sort(res.begin(), res.end());
        return res;
    }
};