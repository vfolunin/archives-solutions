class Solution {
public:
    int countElements(vector<int> &a, int count) {
        if (!count)
            return a.size();

        sort(a.begin(), a.end());

        int res = a.size() - count;
        while (res && a[res - 1] == a[res])
            res--;
        return res;
    }
};