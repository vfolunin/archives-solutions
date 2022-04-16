class Solution {
public:
    int missingNumber(vector<int> &a) {
        int sum = a.size() * (a.size() + 1) / 2;
        for (int value : a)
            sum -= value;
        return sum;
    }
};