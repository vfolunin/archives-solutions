class Solution {
public:
    int minOperations(vector<int> &a, int threshold) {
        return count_if(a.begin(), a.end(), [&](int value) {
            return value < threshold;
        });
    }
};