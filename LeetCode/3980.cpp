class Solution {
public:
    int minOperations(string &a, string &b) {
        if (a.size() == 1) {
            if (a == b)
                return 0;
            else if (a[0] == '0')
                return 1;
            else
                return -1;
        }

        int res = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i])
                continue;

            res++;

            if (a[i] == '1') {
                if (i + 1 < a.size() && a[i + 1] == '1')
                    a[i + 1] = '0';
                else
                    res++;
            }
        }

        return res;
    }
};