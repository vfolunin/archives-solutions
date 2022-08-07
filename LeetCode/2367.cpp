class Solution {
public:
    int arithmeticTriplets(vector<int> &a, int diff) {
        int res = 0;
        for (int value : a)
            res += binary_search(a.begin(), a.end(), value + diff) &&
                   binary_search(a.begin(), a.end(), value + 2 * diff);
        return res;
    }
};