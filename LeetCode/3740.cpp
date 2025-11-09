class Solution {
public:
    int minimumDistance(vector<int> &a) {
        int res = 1e9;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                for (int k = j + 1; k < a.size(); k++)
                    if (a[i] == a[j] && a[i] == a[k])
                        res = min(res, (k - i) * 2);
        return res != 1e9 ? res : -1;
    }
};