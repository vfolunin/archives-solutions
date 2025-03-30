class Solution {
public:
    int longestPalindrome(string &a, string &b) {
        vector<int> al(a.size(), 1);
        for (int i = 0; i < a.size(); i++)
            for (int l = i, r = i; 0 <= l && r < a.size() && a[l] == a[r]; l--, r++)
                al[l] = max(al[l], r - l + 1);
        for (int i = 0; i + 1 < a.size(); i++)
            for (int l = i, r = i + 1; 0 <= l && r < a.size() && a[l] == a[r]; l--, r++)
                al[l] = max(al[l], r - l + 1);
        
        vector<int> br(b.size(), 1);
        for (int i = 0; i < b.size(); i++)
            for (int l = i, r = i; 0 <= l && r < b.size() && b[l] == b[r]; l--, r++)
                br[r] = max(br[r], r - l + 1);
        for (int i = 0; i + 1 < b.size(); i++)
            for (int l = i, r = i + 1; 0 <= l && r < b.size() && b[l] == b[r]; l--, r++)
                br[r] = max(br[r], r - l + 1);

        vector<vector<int>> size(a.size(), vector<int>(b.size()));
        int res = 0;
        for (int l = a.size() - 1; l >= 0; l--) {
            for (int r = 0; r < b.size(); r++) {
                size[l][r] = max(al[l], br[r]);
                if (a[l] == b[r]) {
                    if (l + 1 < a.size() && r >= 1)
                        size[l][r] = max(size[l][r], 2 + size[l + 1][r - 1]);
                    else if (l + 1 < a.size())
                        size[l][r] = max(size[l][r], 2 + al[l + 1]);
                    else if (r >= 1)
                        size[l][r] = max(size[l][r], 2 + br[r - 1]);
                    else
                        size[l][r] = max(size[l][r], 2);
                }
                res = max(res, size[l][r]);
            }
        }
        return res;
    }
};