class Solution {
public:
    bool canBeEqual(string &a, string &b) {
        if (a == b)
            return 1;
        
        swap(a[0], a[2]);
        if (a == b)
            return 1;
        
        swap(a[1], a[3]);
        if (a == b)
            return 1;
        
        swap(a[0], a[2]);
        if (a == b)
            return 1;
        
        return 0;
    }
};