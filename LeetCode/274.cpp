class Solution {
public:
    int hIndex(vector<int> &a) {
        sort(a.rbegin(), a.rend());
        int res = 0;
        while (res < a.size() && a[res] >= res + 1)
            res++;
        return res;
    }
};