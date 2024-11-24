class Solution {
public:
    bool canAliceWin(int n) {
        for (int i = 10; 1; i--) {
            if (n < i)
                return i % 2;
            n -= i;
        }
    }
};