class Solution {
public:
    int minOperations(vector<int> &a, vector<int> &locked, int unlockLimit) {
        int maxValue = 0, res = 0;
        for (int i = 0; i < a.size(); i++) {
            maxValue = max(maxValue, a[i]);
            res += locked[i] && (a[i] != i + 1 || a[i] < maxValue);
        }
        if (res > unlockLimit)
            return -1;
        
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                res += a[i] > a[j];
        return res;
    }
};