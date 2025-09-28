class Solution {
public:
    int maxDistance(vector<string> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                if (a[i] != a[j])
                    res = max(res, j - i + 1);
        return res;
    }
};