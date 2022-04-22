class Solution {
public:
    int numberOfSteps(int n) {
        int res = 0;
        while (n) {
            if (n % 2)
                n--;
            else
                n /= 2;
            res++;
        }
        return res;
    }
};