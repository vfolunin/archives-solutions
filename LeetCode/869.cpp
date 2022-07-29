class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        do {
            if (s[0] == '0')
                continue;
            
            int x = stoi(s);
            if (!(x & (x - 1)))
                return 1;
        } while (next_permutation(s.begin(), s.end()));
        
        return 0;
    }
};