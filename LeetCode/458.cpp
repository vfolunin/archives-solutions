class Solution {
public:
    int poorPigs(int bucketCount, int deathTime, int testTime) {
        int testCount = testTime / deathTime, power = 1, res = 0;
        
        while (power < bucketCount) {
            power *= testCount + 1;
            res++;
        }
        
        return res;
    }
};