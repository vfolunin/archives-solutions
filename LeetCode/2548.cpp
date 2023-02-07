class Solution {
public:
    double maxPrice(vector<vector<int>> &items, int capacity) {
        sort(items.begin(), items.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] * b[1] > b[0] * a[1];
        });

        double res = 0;
        for (vector<int> &item : items) {
            if (capacity >= item[1]) {
                res += item[0];
                capacity -= item[1];
            } else {
                res += (double)capacity / item[1] * item[0];
                capacity = 0;
                break;
            }
        }

        return capacity ? -1 : res;
    }
};