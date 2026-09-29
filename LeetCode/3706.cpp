class Solution {
public:
    int maxDistance(vector<string> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j : { 0, (int)a.size() - 1 })
                if (a[i] != a[j])
                    res = max(res, abs(i - j) + 1);
        return res;
    }
};