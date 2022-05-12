class Solution {
    bool isGood(int n) {
        while (n) {
            if (n % 10 == 0)
                return 0;
            n /= 10;
        }
        return 1;
    }
    
public:
    vector<int> getNoZeroIntegers(int n) {
        int i = 1;
        while (!isGood(i) || !isGood(n - i))
            i++;
        return { i, n - i };
    }
};