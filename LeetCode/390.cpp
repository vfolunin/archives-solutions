class Solution {
    int firstRemaining(int n) {
        if (n == 1)
            return 1;
        return lastRemaining(n / 2) * 2 - (n % 2 == 0);
    }
    
public:
    int lastRemaining(int n) {
        if (n == 1)
            return 1;
        return firstRemaining(n / 2) * 2;
    }
};