class Solution {
public:
    int minimumAddedCoins(vector<int> &a, int target) {
        sort(a.begin(), a.end());

        long long sum = 0;
        int res = 0;

        for (int value : a) {
            while (sum + 1 < value) {
                sum += sum + 1;
                res++;
            }
            sum += value;
        }

        while (sum < target) {
            sum += sum + 1;
            res++;
        }

        return res;
    }
};