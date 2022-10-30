class Solution {
    int digitSum(long long n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long res = 0, add = 1;
        
        while (digitSum(n) > target) {
            n++;
            res += add;
            while (n % 10 == 0) {
                n /= 10;
                add *= 10;
            }
        }
        
        return res;
    }
};