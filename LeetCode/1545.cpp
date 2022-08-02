class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1)
            return '0';
        
        int halfSize = (1 << (n - 1)) - 1;
        
        if (k <= halfSize)
            return findKthBit(n - 1, k);
        else if (k == halfSize + 1)
            return '1';
        else
            return '0' + '1' - findKthBit(n - 1,  2 * (halfSize + 1) - k);
    }
};