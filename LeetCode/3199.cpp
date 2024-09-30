class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }

public:
    int tripletCount(vector<int> &a, vector<int> &b, vector<int> &c) {
        int res = 0;
        for (int aValue : a)
            for (int bValue : b)
                for (int cValue : c)
                    res += ones(aValue ^ bValue ^ cValue) % 2 == 0;
        return res;
    }
};