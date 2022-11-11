class Solution {
    const long long MOD = 1e5;
    
    int trailingZeroCount(int l, int r) {
        int k2 = 0, k5 = 0;
        for (int value = l; value <= r; value++) {
            for (int n = value; n % 2 == 0; n /= 2)
                k2++;
            for (int n = value; n % 5 == 0; n /= 5)
                k5++;
        }
        return min(k2, k5);
    }
    
    long long firstDigits(int l, int r) {
        double product = 1;
        for (int value = l; value <= r; value++) {
            product *= value;
            while (product > 1)
                product /= 10;
        }
        return product * 1e5;
    }
    
    long long lastDigits(int l, int r) {
        long long product = 1;
        for (int value = l; value <= r; value++) {
            product *= value;
            while (product % 10 == 0)
                product /= 10;
            product %= MOD * MOD;
        }
        return product % MOD;
    }
    
    int digitCount(int l, int r) {
        int res = 0;
        double product = 1;
        for (int value = l; value <= r; value++) {
            product *= value;
            while (product > 1) {
                product /= 10;
                res++;
            }
        }
        return res;
    }
    
public:
    string abbreviateProduct(int l, int r) {
        int d = digitCount(l, r), z = trailingZeroCount(l, r);
        
        if (d - z <= 10) {
            long long product = 1;
            for (int value = l; value <= r; value++) {
                product *= value;
                while (product % 10 == 0)
                    product /= 10;
            }
            
            return to_string(product) + "e" + to_string(z);
        } else {
            string suffix = to_string(lastDigits(l, r));
            suffix = string(5 - suffix.size(), '0') + suffix;
            
            return to_string(firstDigits(l, r)) + "..." + suffix + "e" + to_string(z);
        }
    }
};