class Solution {
public:
    int longestCommonPrefix(string &a, string &b) {
        int shift = 0;
        for (int i = 0; i + shift < a.size() && i < b.size(); i++)
            while (a[i + shift] != b[i])
                if (++shift > 1)
                    return i;
        return min(a.size() - shift, b.size());
    }
};