class Solution {
public:
    int numberOfAlternatingGroups(vector<int> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += a[i] != a[(i + 1) % a.size()] && a[i] == a[(i + 2) % a.size()];
        return res;
    }
};