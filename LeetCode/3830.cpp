class Solution {
public:
    int longestAlternating(vector<int> &a) {
        int res = 1;

        vector<int> lUp(a.size(), 1), lDown(a.size(), 1);
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] < a[i])
                lUp[i] += lDown[i - 1];
            else if (a[i - 1] > a[i])
                lDown[i] += lUp[i - 1];

            res = max({ res, lUp[i], lDown[i] });
        }
        
        vector<int> rUp(a.size(), 1), rDown(a.size(), 1);
        for (int i = (int)a.size() - 2; i >= 0; i--) {
            if (a[i] < a[i + 1])
                rUp[i] += rDown[i + 1];
            else if (a[i] > a[i + 1])
                rDown[i] += rUp[i + 1];
                
            res = max({ res, rUp[i], rDown[i] });
        }

        for (int i = 1; i + 1 < a.size(); i++) {
            if (a[i - 1] < a[i + 1])
                res = max(res, lDown[i - 1] + rDown[i + 1]);
            else if (a[i - 1] > a[i + 1])
                res = max(res, lUp[i - 1] + rUp[i + 1]);
        }

        return res;
    }
};