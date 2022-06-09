class Solution {
public:
    bool containsPattern(vector<int> &a, int w, int k) {
        int row = 0;
        for (int i = w; i < a.size(); i++) {
            if (a[i - w] == a[i]) {
                row++;
                if (row == w * (k - 1))
                    return 1;
            } else {
                row = 0;
            }
        }
        return 0;
    }
};