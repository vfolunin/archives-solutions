class Solution {
public:
    vector<int> findPeaks(vector<int> &a) {
        vector<int> res;
        for (int i = 1; i + 1 < a.size(); i++)
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
                res.push_back(i);
        return res;
    }
};