class Solution {
    int firstDigit(long long value) {
        while (value >= 10)
            value /= 10;
        return value;
    }

public:
    int countValidSubarrays(vector<int> &a, int digit) {
        int res = 0;
        for (int l = 0; l < a.size(); l++) {
            long long sum = 0;
            for (int r = l; r < a.size(); r++) {
                sum += a[r];
                res += sum % 10 == digit && firstDigit(sum) == digit;
            }
        }
        return res;
    }
};