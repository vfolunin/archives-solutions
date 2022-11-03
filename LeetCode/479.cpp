class Solution {
public:
    int largestPalindrome(int size) {
        if (size == 1)
            return 9;
        
        int p = 1;
        for (int i = 0; i < size; i++)
            p *= 10;
        
        for (int i = p - 1; 1; i--) {
            string s = to_string(i);
            s.insert(s.end(), s.rbegin(), s.rend());
            long long n = stoll(s);
            
            for (long long d = p; d * d >= n; d--)
                if (n % d == 0 && n / d <= p)
                    return n % 1337;
        }
    }
};