class Solution {
public:
    int wiggleMaxLength(vector<int> &a) {
        int up = 1, down = 1;
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] < a[i])
                up = down + 1;
            else if (a[i - 1] > a[i])
                down = up + 1;
        }
        return max(up, down);
    }
};