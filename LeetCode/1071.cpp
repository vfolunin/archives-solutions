class Solution {
public:
    string gcdOfStrings(string a, string b) {
        int size = gcd(a.size(), b.size());
        
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i % size])
                return "";
        
        for (int i = 0; i < b.size(); i++)
            if (a[i % size] != b[i])
                return "";
        
        return a.substr(0, size);
    }
};