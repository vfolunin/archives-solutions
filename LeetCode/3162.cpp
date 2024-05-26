class Solution {
public:
    int numberOfPairs(vector<int> &a, vector<int> &b, int k) {
        int res = 0;
        for (int aValue : a)
            for (int bValue : b)
                res += aValue % (bValue * k) == 0;
        return res;
    }
};