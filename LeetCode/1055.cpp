class Solution {
    int getMask(string &s) {
        int mask = 0;
        for (char c : s)
            mask |= 1 << (c - 'a');
        return mask;
    }

public:
    int shortestWay(string &a, string &b) {
        if (getMask(b) & ~getMask(a))
            return -1;
        
        int res = 0;
        for (int bi = b.size() - 1; bi >= 0; ) {
            for (int ai = a.size() - 1; ai >= 0; ai--)
                if (bi >= 0 && a[ai] == b[bi])
                    bi--;
            res++;
        }
        return res;
    }
};