class Solution {
public:
    int compareVersion(string &sa, string &sb) {
        stringstream ssa(sa), ssb(sb);
        
        while (ssa || ssb) {
            int a = 0, b = 0;
            char c;
            
            if (ssa)
                ssa >> a >> c;
            if (ssb)
                ssb >> b >> c;
            
            if (a != b)
                return a < b ? -1 : 1;
        }
        
        return 0;
    }
};