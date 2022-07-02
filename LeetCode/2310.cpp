class Solution {
public:
    int minimumNumbers(int sum, int d) {
        if (!sum)
            return 0;
        
        for (int k = 1; k <= 10; k++)
            if (k * d % 10 == sum % 10 && k * d <= sum)
                return k;
        
        return -1;
    }
};