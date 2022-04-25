class Solution {
public:
    bool areAlmostEqual(string a, string b) {
        int i = 0;
        while (i < a.size() && a[i] == b[i])
            i++;
        
        if (i == a.size())
            return 1;
        
        int j = i + 1;
        while (j < a.size() && a[j] == b[j])
            j++;
        
        if (j == a.size())
            return 0;
        
        swap(a[i], a[j]);
        return a == b;
    }
};