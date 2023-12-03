class Solution {
public:
    vector<int> findWordsContaining(vector<string> &a, char c) {
        vector<int> res;
        for (int i = 0; i < a.size(); i++)
            if (a[i].find(c) != -1)
                res.push_back(i);
        return res;
    }
};