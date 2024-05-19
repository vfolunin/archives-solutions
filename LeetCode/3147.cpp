class Solution {
public:
    int maximumEnergy(vector<int> &a, int jump) {
        vector<int> res(a.size());
        for (int i = res.size() - 1; i >= 0; i--)
            res[i] = a[i] + (i + jump < res.size() ? res[i + jump] : 0);
        return *max_element(res.begin(), res.end());
    }
};