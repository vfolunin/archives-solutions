class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res = 0;
        for (int count1 = 0; count1 * cost1 <= total; count1++)
            res += (total - count1 * cost1) / cost2 + 1;
        return res;
    }
};