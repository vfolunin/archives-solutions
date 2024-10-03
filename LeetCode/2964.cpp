class Solution {
public:
    int divisibleTripletCount(vector<int> &a, int divisor) {
        unordered_map<int, int> l, r;
        for (int value : a)
            r[value % divisor]++;
        
        int res = 0;
        for (int value : a) {
            r[value % divisor]--;

            for (auto &[lValue, lCount] : l) {
                int rValue = (divisor - (lValue + value) % divisor) % divisor;
                res += l[lValue] * r[rValue];
            }

            l[value % divisor]++;
        }
        return res;
    }
};