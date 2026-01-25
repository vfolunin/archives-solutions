class Solution {
public:
    int minimumPrefixLength(vector<int> &a) {
        int i = a.size() - 1;
        while (i && a[i - 1] < a[i])
            i--;
        return i;
    }
};