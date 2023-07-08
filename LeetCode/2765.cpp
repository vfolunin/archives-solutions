class Solution {
public:
    int alternatingSubarray(vector<int> &a) {
        int res = -1;

        for (int from = 0; from + 1 < a.size(); from++) {
            if (a[from] + 1 != a[from + 1])
                continue;

            for (int len = 2; from + len <= a.size(); len++) {
                if (a[from + len - 1] == a[from + (len - 1) % 2])
                    res = max(res, len);
                else
                    break;
            }
        }

        return res;
    }
};