class Solution {
    int digitSum(int n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    
public:
    int sumOfDigits(vector<int> &a) {
        return digitSum(*min_element(a.begin(), a.end())) % 2 == 0;
    }
};