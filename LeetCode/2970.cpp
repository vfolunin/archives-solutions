class Solution {
public:
    int incremovableSubarrayCount(vector<int> &a) {
        int res = 0;
        for (int l = 0; l < a.size(); l++) {
            for (int r = l; r < a.size(); r++) {
                vector<int> b = a;
                b.erase(b.begin() + l, b.begin() + r + 1);

                bool ok = 1;
                for (int i = 0; i + 1 < b.size() && ok; i++)
                    ok &= b[i] < b[i + 1];
                res += ok;
            }
        }
        return res;
    }
};