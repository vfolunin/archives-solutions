class Solution {
public:
    long long minimumCost(string &a, string &b, int flipCost, int swapCost, int crossCost) {
        int count01 = 0, count10 = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                count01 += a[i] == '0';
                count10 += a[i] == '1';
            }
        }

        long long count = min(count01, count10);
        long long res = count * min(2 * flipCost, swapCost);
        
        count = max(count01, count10) - count;
        res += count / 2 * min(2 * flipCost, swapCost + crossCost);

        if (count % 2)
            res += flipCost;
        return res;
    }
};