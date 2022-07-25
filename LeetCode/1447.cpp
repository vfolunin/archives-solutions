class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        
        for (int den = 1; den <= n; den++)
            for (int num = 1; num < den; num++)
                if (gcd(num, den) == 1)
                    res.push_back(to_string(num) + "/" + to_string(den));
        
        return res;
    }
};