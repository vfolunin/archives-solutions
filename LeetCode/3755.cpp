class Solution {
public:
    int maxBalancedSubarray(vector<int> &a) {
        map<pair<int, int>, int> lastPos;
        int balance = 0, xorSum = 0;
        lastPos[{ balance, xorSum }] = -1;

        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            balance += a[i] % 2 ? 1 : -1;
            xorSum ^= a[i];

            if (lastPos.count({ balance, xorSum }))
                res = max(res, i - lastPos[{ balance, xorSum }]);
            else
                lastPos[{ balance, xorSum }] = i;
        }
        return res;
    }
};