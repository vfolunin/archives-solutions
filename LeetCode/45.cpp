class Solution {
public:
    int jump(vector<int> &a) {
        if (a.size() == 1)
            return 0;
        
        int jumpCount = 1, from = 0, to = a[0];
        
        while (to < a.size() - 1) {
            int nextTo = to;
            while (from <= to) {
                nextTo = max(nextTo, from + a[from]);
                from++;
            }
            
            to = nextTo;
            jumpCount++;
        }
        
        return jumpCount;
    }
};