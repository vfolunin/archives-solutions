class Solution {
public:
    void duplicateZeros(vector<int> &a) {
        vector<int> res;
        for (int i = 0; res.size() < a.size(); i++) {
            res.push_back(a[i]);
            if (!a[i] && res.size() < a.size())
                res.push_back(0);
        }
        a.swap(res);
    }
};