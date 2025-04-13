class Solution {
public:
    int minOperations(vector<int> &a, int mod) {
        int sum = 0;
        for (int value : a)
            sum += value;
        return sum % mod;
    }
};