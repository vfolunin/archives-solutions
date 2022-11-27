class Solution {
public:
    int appendCharacters(string &a, string &b) {
        int bi = 0;
        for (int ai = 0; ai < a.size(); ai++)
            if (bi < b.size() && a[ai] == b[bi])
                bi++;
        return b.size() - bi;
    }
};