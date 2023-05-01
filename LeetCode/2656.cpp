class Solution {
public:
    int maximizeSum(vector<int> &a, int opCount) {
        int maxValue = *max_element(a.begin(), a.end()), res = 0;
        for (int i = 0; i < opCount; i++)
            res += maxValue + i;
        return res;
    }
};