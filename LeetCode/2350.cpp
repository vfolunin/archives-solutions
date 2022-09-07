class Solution {
public:
    int shortestSequence(vector<int> &a, int k) {
        int foundCount = 0, i = 0, res = 1;
        vector<int> found(k);
        
        for ( ; i < a.size(); i++) {
            foundCount += !found[a[i] - 1];
            found[a[i] - 1] = 1;
            
            if (foundCount == k) {
                res++;
                foundCount = 0;
                found.assign(k, 0);
            }
        }
        
        return res;
    }
};