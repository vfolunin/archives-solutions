class Solution {
public:
    int maximizeWin(vector<int> &a, int width) {
        if (a.size() == 1)
            return 1;
        
        vector<int> lMaxCount(a.size());
        for (int l = 0, r = 0; r < a.size(); r++) {
            while (a[r] - a[l] > width)
                l++;

            lMaxCount[r] = r - l + 1;

            if (r)
                lMaxCount[r] = max(lMaxCount[r], lMaxCount[r - 1]);
        }

        vector<int> rCount(a.size());
        for (int l = a.size() - 1, r = a.size() - 1; l >= 0; l--) {
            while (a[r] - a[l] > width)
                r--;

            rCount[l] = r - l + 1;
        }
        
        int res = 0;
        for (int i = 0; i + 1 < a.size(); i++)
            res = max(res, lMaxCount[i] + rCount[i + 1]);
        return res;
    }
};