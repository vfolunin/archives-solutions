class Solution {
public:
    int minMergedInteger(vector<int> &a) {
        int res = 1e9;
        for (int i = 0; i < a.size(); i += 2)
            res = min(res, stoi(to_string(a[i]) + to_string(a[i + 1])));
        return res;
    }
};