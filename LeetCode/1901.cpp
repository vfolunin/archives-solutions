class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>> &a) {
        int l = 0, r = a.size() - 1;
        while (l < r) {
            cout << l << " " << r << endl;
            int m = l + (r - l) / 2;
            int x = max_element(a[m].begin(), a[m].end()) - a[m].begin();
            if (a[m][x] < a[m + 1][x])
                l = m + 1;
            else
                r = m;
        }
        int x = max_element(a[l].begin(), a[l].end()) - a[l].begin();
        return { l, x };
    }
};