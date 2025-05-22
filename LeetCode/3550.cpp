class Solution {
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    
public:
    int smallestIndex(vector<int> &a) {
        for (int i = 0; i < a.size(); i++)
            if (digitSum(a[i]) == i)
                return i;
        return -1;
    }
};