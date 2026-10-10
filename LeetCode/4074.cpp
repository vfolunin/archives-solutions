class Solution {
public:
    vector<int> maxProductPair(vector<int> &a, int targetSum) {
        vector<int> res = { -1, -1 };
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < a.size(); j++)
                if (a[i] + a[j] == targetSum && a[i] > a[j] &&
                    (res[0] == -1 || a[res[0]] * a[res[1]] < a[i] * a[j]))
                    res = { i, j };
        return res;
    }
};