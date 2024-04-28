class Solution {
public:
    long long minEnd(int size, int andSum) {
        size--;
        long long res = andSum;

        for (int i = 0, j = 0; i < 60; i++)
            if ((res & (1LL << i)) == 0)
                res |= (((long long)size >> j++) & 1) << i;
        
        return res;
    }
};