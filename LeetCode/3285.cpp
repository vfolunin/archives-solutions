class Solution {
public:
    vector<int> stableMountains(vector<int> &a, int threshold) {
        vector<int> res;
        for (int i = 1; i < a.size(); i++)
            if (a[i - 1] > threshold)
                res.push_back(i);
        return res;
    }
};