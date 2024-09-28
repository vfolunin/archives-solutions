class Solution {
public:
    int maxValue(vector<int> &a, int takeLimit) {
        vector canL(a.size() + 1, vector(takeLimit + 1, vector<int>(128)));
        canL[0][0][0] = 1;
        for (int i = 0; i < a.size(); i++) {
            for (int taken = 0; taken <= takeLimit; taken++) {
                for (int value = 0; value < 128; value++) {
                    canL[i + 1][taken][value] |= canL[i][taken][value];
                    if (taken < takeLimit)
                        canL[i + 1][taken + 1][value | a[i]] |= canL[i][taken][value];
                }
            }
        }

        vector canR(a.size() + 1, vector(takeLimit + 1, vector<int>(128)));
        canR[a.size()][0][0] = 1;
        for (int i = a.size(); i; i--) {
            for (int taken = 0; taken <= takeLimit; taken++) {
                for (int value = 0; value < 128; value++) {
                    canR[i - 1][taken][value] |= canR[i][taken][value];
                    if (taken < takeLimit)
                        canR[i - 1][taken + 1][value | a[i - 1]] |= canR[i][taken][value];
                }
            }
        }

        int res = 0;
        for (int i = 0; i <= a.size(); i++)
            for (int valueL = 0; valueL < 128; valueL++)
                if (canL[i][takeLimit][valueL])
                    for (int valueR = 0; valueR < 128; valueR++)
                        if (canR[i][takeLimit][valueR])
                            res = max(res, valueL ^ valueR);
        return res;
    }
};