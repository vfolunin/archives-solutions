class Solution {
public:
    bool buddyStrings(string a, string b) {
        if (a.size() != b.size())
            return 0;
        
        int l = 0;
        while (l < a.size() && a[l] == b[l])
            l++;
        
        if (l == a.size())
            return unordered_set(a.begin(), a.end()).size() < a.size();
        
        int r = a.size() - 1;
        while (a[r] == b[r])
            r--;
        
        if (l == r)
            return 0;
        
        swap(a[l], a[r]);
        return a == b;
    }
};