class Solution {
public:
    string multiply(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string res(a.size() + b.size(), '0');
        for (int ai = 0; ai < a.size(); ai++) {
            int carry = 0;
            for (int bi = 0; bi < b.size() || carry; bi++) {
                int ad = ai < a.size() ? a[ai] - '0' : 0;
                int bd = bi < b.size() ? b[bi] - '0' : 0;
                int sum = (res[ai + bi] - '0') + ad * bd + carry;
                res[ai + bi] = sum % 10 + '0';
                carry = sum / 10;
            }
        }
        
        while (res.size() > 1 && res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        
        return res;
    }
};