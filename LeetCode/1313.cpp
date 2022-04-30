class Solution {
public:
    vector<int> decompressRLElist(vector<int> &a) {
        vector<int> res;
        for (int i = 0; i < a.size(); i += 2)
            for (int j = 0; j < a[i]; j++)
                res.push_back(a[i + 1]);
        return res;
    }
};