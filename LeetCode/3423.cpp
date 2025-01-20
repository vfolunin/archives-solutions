class Solution {
public:
    int maxAdjacentDistance(vector<int> &a) {
        int res = abs(a.front() - a.back());
        for (int i = 0; i + 1 < a.size(); i++)
            res = max(res, abs(a[i] - a[i + 1]));
        return res;
    }
};