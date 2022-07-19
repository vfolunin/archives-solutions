class Solution {
public:
    long long smallestNumber(long long n) {
        string s = to_string(abs(n));
        
        if (n < 0) {
            sort(s.rbegin(), s.rend());
            return -stoll(s);
        }
        
        sort(s.begin(), s.end());
        
        int i = 0;
        while (i < s.size() && s[i] == '0')
            i++;
        if (i < s.size())
            swap(s[0], s[i]);
        
        return stoll(s);
    }
};