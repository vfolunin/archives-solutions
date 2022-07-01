class Solution {
public:
    int findNthDigit(int n) {
        n--;
        
        long long size = 1, count = 9, from = 1;
        while (n > count * size) {
            n -= count * size;
            size++;
            count *= 10;
            from *= 10;
        }
        
        int number = n / size, digit = n % size;
        return to_string(from + number)[digit] - '0';
    }
};