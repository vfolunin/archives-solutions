const long long MOD = 1e9 + 7;
 
long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

long long inv(long long x) {
    return binPow(x, MOD - 2, MOD);
}

class Fancy {
    vector<long long> a, add = { 0 }, mul = { 1 };
    
public:    
    void append(int val) {
        a.push_back(val);
        add.push_back(add.back());
        mul.push_back(mul.back());
    }
    
    void addAll(int value) {
        add.back() = (add.back() + value) % MOD;
    }
    
    void multAll(int value) {
        add.back() = add.back() * value % MOD;
        mul.back() = mul.back() * value % MOD;
    }
    
    int getIndex(int index) {
        if (index >= a.size())
            return - 1;
        
        long long curMul = mul.back() * inv(mul[index]) % MOD;
        long long curAdd = (add.back() - add[index] * curMul % MOD + MOD) % MOD;        
        return (a[index] * curMul + curAdd) % MOD;
    }
};