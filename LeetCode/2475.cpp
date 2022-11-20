class Solution {
public:
    int unequalTriplets(vector<int> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                for (int k = j + 1; k < a.size(); k++)
                    res += a[i] != a[j] && a[i] != a[k] && a[j] != a[k];
        return res;
    }
};