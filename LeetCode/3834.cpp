class Solution {
public:
    vector<long long> mergeAdjacent(vector<int> &a) {
        vector<long long> res;
        for (int value : a) {
            res.push_back(value);
            while (res.size() > 1 && res[res.size() - 2] == res.back()) {
                res[res.size() - 2] += res.back();
                res.pop_back();
            }
        }
        return res;
    }
};