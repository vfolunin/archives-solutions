class Solution {
    int getLength(vector<int> &a, int divisor, int remainder) {
        vector<int> length(divisor);
        for (int value : a) 
            length[value % divisor] = length[(remainder + divisor - value % divisor) % divisor] + 1;
        return *max_element(length.begin(), length.end());
    }

public:
    int maximumLength(vector<int> &a, int divisor) {
        int res = 0;
        for (int remainder = 0; remainder < divisor; remainder++)
            res = max(res, getLength(a, divisor, remainder));
        return res;
    }
};