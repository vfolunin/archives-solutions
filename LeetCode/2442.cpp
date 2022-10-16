class Solution {
    int reverse(int n) {
        int res = 0;
        while (n > 9) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        res = res * 10 + n;
        return res;
    }
    
public:
    int countDistinctIntegers(vector<int> &a) {
        unordered_set<int> values(a.begin(), a.end());
        for (int value : a)
            values.insert(reverse(value));
        return values.size();
    }
};