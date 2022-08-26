class Solution {
    vector<int> getDivisors(int n) {
        vector<int> divisors;

        for (int d = 1; divisors.size() <= 4 && d * d <= n; d++) {
            if (n % d == 0) {
                divisors.push_back(d);
                if (d * d != n)
                    divisors.push_back(n / d);
            }
        }

        return divisors;
    }
    
public:
    int sumFourDivisors(vector<int> &a) {
        int res = 0;
        
        for (int value : a) {
            vector<int> divisors = getDivisors(value);
            
            if (divisors.size() == 4)
                for (int d : divisors)
                    res += d;            
        }
        
        return res;
    }
};