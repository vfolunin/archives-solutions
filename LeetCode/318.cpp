class Solution {
public:
    int maxProduct(vector<string> &words) {
        vector<int> masks(words.size());
        for (int i = 0; i < words.size(); i++)
            for (char c : words[i])
                masks[i] |= 1 << (c - 'a');
        
        int res = 0;
        for (int i = 0; i < words.size(); i++)
            for (int j = i + 1; j < words.size(); j++)
                if (!(masks[i] & masks[j]))
                    res = max<int>(res, words[i].size() * words[j].size());
        return res;
    }
};