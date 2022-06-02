class Solution {
public:
    int findKthPositive(vector<int> &a, int k) {
        int i = 0, value = 1;
        while (1) {
            if (i < a.size() && a[i] == value) {
                i++;
                value++;
            } else if (--k) {
                value++;
            } else {
                return value;
            }
        }
    }
};