class Solution {
    int getLength(vector<int> &a, int remainder) {
        vector<int> length(2);
        for (int value : a) 
            length[value % 2] = length[(remainder + 2 - value % 2) % 2] + 1;
        return *max_element(length.begin(), length.end());
    }

public:
    int maximumLength(vector<int> &a) {
        int res = 0;
        for (int remainder = 0; remainder < 2; remainder++)
            res = max(res, getLength(a, remainder));
        return res;
    }
};