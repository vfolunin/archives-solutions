class Solution {
public:
    int dietPlanPerformance(vector<int> &a, int width, int l, int r) {
        int sum = accumulate(a.begin(), a.begin() + width, 0);
        int res = 0;
        res -= sum < l;
        res += sum > r;

        for (int i = width; i < a.size(); i++) {
            sum += a[i] - a[i - width];
            res -= sum < l;
            res += sum > r;
        }

        return res;
    }
};