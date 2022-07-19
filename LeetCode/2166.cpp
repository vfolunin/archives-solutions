class Bitset {
    int ones = 0, flipped = 0;
    string s;
    
public:
    Bitset(int size) : s(size, '0') {}
    
    void fix(int idx) {
        if (flipped) {
            ones -= s[idx] == '1';
            s[idx] = '0';
        } else {
            ones += s[idx] == '0';
            s[idx] = '1';
        }
    }
    
    void unfix(int idx) {
        if (flipped) {
            ones += s[idx] == '0';
            s[idx] = '1';
        } else {
            ones -= s[idx] == '1';
            s[idx] = '0';
        }
    }
    
    void flip() {
        flipped ^= 1;
    }
    
    bool all() {
        if (flipped)
            return !ones;
        else
            return ones == s.size();
    }
    
    bool one() {
        if (flipped)
            return ones < s.size();
        else
            return ones;
    }
    
    int count() {
        if (flipped)
            return s.size() - ones;
        else
            return ones;
    }
    
    string toString() {
        if (flipped) {
            string res = s;
            for (char &c : res)
                c ^= 1;
            return res;
        }
        return s;
    }
};