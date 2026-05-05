class Solution {
public:
    vector<int> countOppositeParity(vector<int> &a) {
        vector<int> res(a.size());
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                res[i] += a[i] % 2 != a[j] % 2;
        return res;
    }
};