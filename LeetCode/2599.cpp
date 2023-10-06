class Solution {
public:
    int makePrefSumNonNegative(vector<int> &a) {
        multiset<int> values;
        long long sum = 0;
        int res = 0;

        for (int value : a) {
            values.insert(value);
            sum += value;

            if (sum < 0) {
                sum -= *values.begin();
                values.erase(values.begin());
                res++;
            }
        }
        
        return res;
    }
};