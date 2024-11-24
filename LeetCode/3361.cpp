class Solution {
public:
    long long shiftDistance(string &a, string &b, vector<int> &nextCost, vector<int> &prevCost) {
        long long res = 0;

        for (int i = 0; i < a.size(); i++) {
            long long totalNextCost = 0;
            for (char c = a[i]; c != b[i]; c = (c - 'a' + 1) % 26 + 'a')
                totalNextCost += nextCost[c - 'a'];

            long long totalPrevCost = 0;
            for (char c = a[i]; c != b[i]; c = (c - 'a' + 25) % 26 + 'a')
                totalPrevCost += prevCost[c - 'a'];
            
            res += min(totalNextCost, totalPrevCost);
        }
        
        return res;
    }
};