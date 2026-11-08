class Solution {
public:
    int countSuffix(vector<int> &a, vector<int> &b) {
        if (unordered_multiset(a.begin(), a.end()) !=
            unordered_multiset(b.begin(), b.end()))
            return 0;

        int l = 0;
        while (l + 1 < a.size() && a[l] == b[l])
            l++;

        int r = b.size() - 1;
        while (r && b[r - 1] >= b[r])
            r--;

        return max(0, l - r + 1);
    }
};