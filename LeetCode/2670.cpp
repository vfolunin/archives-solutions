class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int> &a) {
        vector<int> res(a.size());
        for (int i = 0; i < a.size(); i++)
            res[i] = set(a.begin(), a.begin() + i + 1).size() - set(a.begin() + i + 1, a.end()).size();
        return res;
    }
};