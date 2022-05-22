class Solution {
    int digitCount(int n) {
        int res = 0;
        while (n > 9) {
            res++;
            n /= 10;
        }
        return res + 1;
    }
    
public:
    int findNumbers(vector<int> &a) {
        int res = 0;
        for (int value : a)
            res += digitCount(value) % 2 == 0;
        return res;
    }
};