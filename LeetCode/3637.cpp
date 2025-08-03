class Solution {
public:
    bool isTrionic(vector<int> &a) {
        for (int l = 1; l < a.size(); l++) {
            for (int r = l + 1; r + 1 < a.size(); r++) {
                bool ok = 1;
                for (int i = 0; i < l && ok; i++)
                    ok &= a[i] < a[i + 1];
                for (int i = l; i < r && ok; i++)
                    ok &= a[i] > a[i + 1];
                for (int i = r; i + 1 < a.size() && ok; i++)
                    ok &= a[i] < a[i + 1];
                if (ok)
                    return 1;
            }
        }
        return 0;
    }
};