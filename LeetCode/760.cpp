class Solution {
public:
    vector<int> anagramMappings(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> posInB;
        for (int i = 0; i < b.size(); i++)
            posInB[b[i]] = i;

        vector<int> res(a.size());
        for (int i = 0; i < a.size(); i++)
            res[i] = posInB[a[i]];
        return res;
    }
};