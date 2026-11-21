class Solution {
public:
    vector<string> assignUmbrella(vector<int> &rain) {
        vector<string> res(rain.size(), "None");
        int aCount = 0, bCount = 0;

        for (int i = 0; i < rain.size(); i++) {
            bool aNeed = rain[i] && i + 1 < rain.size() && rain[i + 1];
            bool bNeed = rain[i];

            if (aNeed && (!bNeed || aCount <= bCount)) {
                res[i] = "Alice";
                aCount++;
            } else if (bNeed) {
                res[i] = "Bob";
                bCount++;
            }
        }

        return res;
    }
};