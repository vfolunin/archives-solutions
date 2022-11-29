class Solution {
public:
   int findKthNumber(long long n, long long k) {
        long long prefix = 1;

        for (k--; k; ) {
            long long count = 0;
            for (long long l = prefix, r = l + 1; l <= n; l *= 10, r *= 10) 
                count += min(n + 1, r) - l; 
            
            if (k >= count) {   
                k -= count;
                prefix++;
            } else {   
                k--;
                prefix *= 10;
            }
        }
        
        return prefix;
    }
};