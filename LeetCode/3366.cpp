class Solution {
public:
    int minArraySum(vector<int> &a, int delta, int limit1, int limit2) {
        vector minSum(a.size() + 1, vector(limit1 + 1, vector<int>(limit2 + 1)));

        for (int i = 0; i < a.size(); i++) {
            for (int ops1 = 0; ops1 <= limit1; ops1++) {
                for (int ops2 = 0; ops2 <= limit2; ops2++) {
                    int &res = minSum[i + 1][ops1][ops2];

                    res = minSum[i][ops1][ops2] + a[i];

                    if (ops1)
                        res = min(res, minSum[i][ops1 - 1][ops2] + (a[i] + 1) / 2);
                    
                    if (ops2 && a[i] >= delta)
                        res = min(res, minSum[i][ops1][ops2 - 1] + a[i] - delta);
                    
                    if (ops1 && ops2 && a[i] >= delta) {
                        res = min(res, minSum[i][ops1 - 1][ops2 - 1] + (a[i] - delta + 1) / 2);
                        if ((a[i] + 1) / 2 >= delta)
                            res = min(res, minSum[i][ops1 - 1][ops2 - 1] + (a[i] + 1) / 2 - delta);
                    }
                }
            }
        }

        return minSum.back().back().back();
    }
};