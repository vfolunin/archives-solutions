class Solution {
public:
    int countValidSelections(vector<int> &a) {
        int res = 0;

        int sumL = 0, sumR = accumulate(a.begin(), a.end(), 0);
        for (int value : a) {
            sumL += value;
            sumR -= value;

            if (!value) {
                res += sumL == sumR || sumL + 1 == sumR;
                res += sumL == sumR || sumL == sumR + 1;
            }
        }

        return res;
    }
};