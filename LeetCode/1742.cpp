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
    int countBalls(int l, int r) {
        vector<int> count(50);
        for (int i = l; i <= r; i++)
            count[digitSum(i)]++;
        return *max_element(count.begin(), count.end());
    }
};