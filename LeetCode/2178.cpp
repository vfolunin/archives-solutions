class Solution {
public:
    vector<long long> maximumEvenSplit(long long sum) {
        if (sum % 2)
            return {};
        
        vector<long long> res;
        for (long long i = 2; sum > 0; i += 2) {
            if (sum >= i) {
                sum -= i;
                res.push_back(i);
            } else {
                res.back() += sum;
                break;
            }
        }
        return res;
    }
};