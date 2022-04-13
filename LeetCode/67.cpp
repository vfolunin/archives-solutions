class Solution {
public:
    string addBinary(string &a, string &b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string c(max(a.size(), b.size()), '0');
        int carry = 0;
        for (int i = 0; i < c.size(); i++) {
            int sum = (i < a.size() ? a[i] - '0' : 0) + (i < b.size() ? b[i] - '0' : 0) + carry;
            c[i] += sum % 2;
            carry = sum / 2;
        }
        if (carry)
            c += '1';
        
        reverse(c.begin(), c.end());
        return c;
    }
};