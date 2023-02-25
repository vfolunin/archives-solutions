class Solution {
public:
    long long singleDivisorTriplet(vector<int> &values) {
        vector<long long> count(101);
        for (int value : values)
            count[value]++;
        
        long long res = 0;
        for (int a = 1; a <= 100; a++) {
            for (int b = 1; count[a] && b <= 100; b++) {
                for (int c = 1; count[b] && c <= 100; c++) {
                    int sum = a + b + c;
                    if ((sum % a == 0) + (sum % b == 0) + (sum % c == 0) == 1)
                        res += count[a] * (count[b] - (a == b)) * (count[c] - (a == c || b == c));
                }
            }
        }
        return res;
    }
};