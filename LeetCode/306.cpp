class Solution {
    string add(string &a, string &b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string c;
        for (int i = 0, over = 0; i < a.size() || i < b.size() || over; i++) {
            int ad = i < a.size() ? a[i] - '0' : 0;
            int bd = i < b.size() ? b[i] - '0' : 0;
            int sum = ad + bd + over;
            c += sum % 10 + '0';
            over = sum / 10;
        }
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(c.begin(), c.end());
        return c;
    }
    
    bool check(string &s, int aSize, int bSize) {
        string a = s.substr(0, aSize);
        string b = s.substr(aSize, bSize);
        
        if (aSize > 1 && a[0] == '0' || bSize > 1 && b[0] == '0')
            return 0;
        
        string r = a + b;
        while (r.size() < s.size()) {
            string c = add(a, b);
            a = b;
            b = c;
            r += c;
        }
        
        return r == s;
    }
    
public:
    bool isAdditiveNumber(string s) {
        for (int aSize = 1; aSize < s.size(); aSize++)
            for (int bSize = 1; aSize + bSize < s.size(); bSize++)
                if (check(s, aSize, bSize))
                    return 1;
        return 0;
    }
};