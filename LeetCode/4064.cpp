class Solution {
public:
    int longestSubarray(vector<int> &a, int divisor) {
        int remainder = 0;

        vector<int> lPos(divisor, a.size()), rPos(divisor, -1);
        lPos[remainder] = rPos[remainder] = -1;
        for (int i = 0; i < a.size(); i++) {
            remainder = ((remainder + a[i]) % divisor + divisor) % divisor;
            if (lPos[remainder] == a.size())
                lPos[remainder] = i;
            rPos[remainder] = i;
        }

        vector<int> order;
        for (int remainder = 0; remainder < divisor; remainder++)
            if (lPos[remainder] != a.size())
                order.push_back(remainder);
        sort(order.begin(), order.end(), [&](int lhs, int rhs) {
            return rPos[lhs] < rPos[rhs];
        });

        vector<int> mPos(divisor, -1);
        int i = 0, res = 0;

        for (int rRemainder : order) {
            while (i <= rPos[rRemainder]) {
                int mRemainder = ((a[i] % divisor) + divisor) % divisor;
                mPos[mRemainder] = i;
                i++;
            }

            if (lPos[rRemainder] < rPos[rRemainder])
                res = max(res, rPos[rRemainder] - lPos[rRemainder]);

            for (int mRemainder = 0; mRemainder < divisor; mRemainder++) {
                int lRemainder = ((rRemainder - 2 * mRemainder) % divisor + divisor) % divisor;
                if (lPos[lRemainder] < mPos[mRemainder])
                    res = max(res, rPos[rRemainder] - lPos[lRemainder]);
            }
        }

        return res;
    }
};