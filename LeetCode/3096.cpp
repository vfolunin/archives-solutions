class Solution {
public:
    int minimumLevels(vector<int> &a) {
        int lScore = 0, rScore = 0;
        for (int value : a)
            rScore += value ? 1 : -1;

        for (int i = 0; i + 1 < a.size(); i++) {
            lScore += a[i] ? 1 : -1;
            rScore -= a[i] ? 1 : -1;

            if (lScore > rScore)
                return i + 1;
        }

        return -1;
    }
};