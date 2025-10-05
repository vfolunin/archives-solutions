class Solution {
public:
    int alternatingSum(vector<int> &a) {
        int sum = 0;
        for (int i = 0; i < a.size(); i++)
            sum += a[i] * (i % 2 ? -1 : 1);
        return sum;
    }
};