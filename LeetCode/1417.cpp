class Solution {
public:
    string reformat(string s) {
        string a, b;
        for (char c : s) {
            if (isalpha(c))
                a += c;
            else
                b += c;
        }
        
        if (abs<int>(a.size() - b.size()) > 1)
            return "";
        
        if (a.size() < b.size())
            swap(a, b);
        
        string res;
        for (int i = 0; i < b.size(); i++) {
            res += a[i];
            res += b[i];
        }
        if (a.size() > b.size())
            res += a.back();
        
        return res;
    }
};