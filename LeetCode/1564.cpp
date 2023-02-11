class Solution {
public:
    int maxBoxesInWarehouse(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());

        for (int i = 1; i < b.size(); i++)
            b[i] = min(b[i], b[i - 1]);
        reverse(b.begin(), b.end());

        int ai = 0;
        for (int bi = 0; ai < a.size() && bi < b.size(); ) {
            while (bi < b.size() && a[ai] > b[bi])
                bi++;
            if (bi < b.size()) {
                ai++;
                bi++;
            }
        }
        return ai;
    }
};