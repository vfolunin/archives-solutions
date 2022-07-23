class Solution {
public:
    int countSubstrings(string a, string b) {        
        int res = 0;
        
        for (int ai = 0; ai < a.size(); ai++) {
            for (int bi = 0; bi < b.size(); bi++) {
                int diff = 0;
                for (int i = 0; ai + i < a.size() && bi + i < b.size() && diff < 2; i++) {
                    diff += a[ai + i] != b[bi + i];
                    res += diff == 1;
                }
            }
        }
        
        return res;
    }
};