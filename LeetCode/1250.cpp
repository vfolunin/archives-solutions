class Solution {
public:
    bool isGoodArray(vector<int> &a) {
        int d = 0;
        for (int value : a)
            d = gcd(d, value);
        return d == 1;
    }
};