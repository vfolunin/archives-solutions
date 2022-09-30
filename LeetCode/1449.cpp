class Solution {
public:
    string largestNumber(vector<int> &cost, int target) {
        vector<int> size(target + 1, -1);
        size[0] = 0;
        vector<int> first(target + 1);

        for (int sum = 1; sum <= target; sum++) {
            for (int digit = 8; digit >= 0; digit--) {
                if (sum >= cost[digit] && size[sum - cost[digit]] != -1 && size[sum] < size[sum - cost[digit]] + 1) {
                    size[sum] = size[sum - cost[digit]] + 1;
                    first[sum] = digit;
                }
            }
        }

        if (size[target] == -1)
            return "0";

        string res;
        for (int sum = target; sum; sum -= cost[first[sum]])
            res += (char)(first[sum] + '1');
        return res;
    }
};