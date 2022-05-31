class Solution {
public:
    int getMinDistance(vector<int> &a, int target, int start) {
        int res = 1e9;
        for (int i = 0; i < a.size(); i++)
            if (a[i] == target)
                res = min(res, abs(i - start));
        return res;
    }
};