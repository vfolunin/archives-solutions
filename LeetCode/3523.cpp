class Solution {
public:
    int maximumPossibleSize(vector<int> &a) {
        vector<int> res;
        for (int value : a)
            if (res.empty() || res.back() <= value)
                res.push_back(value);
        return res.size();
    }
};