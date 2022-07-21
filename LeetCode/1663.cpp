class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        
        for (int i = res.size() - 1; i >= 0; i--) {
            int delta = min(25, k);
            res[i] += delta;
            k -= delta;
        }
        
        return res;
    }
};