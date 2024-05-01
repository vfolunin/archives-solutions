class Solution {
public:
    long long minimumMoves(vector<int> &a, int n, int changeLimit) {
        int curRow = 0, maxRow = 0;
        for (int value : a) {
            if (value)
                curRow++;
            else
                curRow = 0;
            maxRow = max(maxRow, curRow);
        }
        maxRow = min({ maxRow, 3, n });

        if (maxRow + changeLimit >= n)
            return max(maxRow - 1, 0) + max(n - maxRow, 0) * 2;
        
        n -= changeLimit;

        vector<int> pos;
        for (int i = 0; i < a.size(); i++)
            if (a[i] == 1)
                pos.push_back(i);
        
        long long lSize = n / 2, lSum = 0;
        for (int i = 0; i < lSize; i++)
            lSum += pos[i];

        long long rSize = n - lSize, rSum = 0;
        for (int i = lSize; i < n; i++)
            rSum += pos[i];

        long long res = lSize * pos[lSize] - lSum + rSum - rSize * pos[lSize];

        for (int l = 1, m = lSize + 1, r = n; r < pos.size(); l++, m++, r++) {
            lSum += pos[m - 1] - pos[l - 1];
            rSum += pos[r] - pos[m - 1];
            res = min(res, lSize * pos[m] - lSum + rSum - rSize * pos[m]);
        }

        return changeLimit * 2 + res;
    }
};