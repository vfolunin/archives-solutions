class Solution {
public:
    int maxDistToClosest(vector<int> &a) {
        int last = -1, res = 0;
        
        for (int i = 0; i < a.size(); i++) {
            if (a[i]) {
                res = max(res, last == -1 ? i : (i - last) / 2);
                last = i;
            }
        }
        
        res = max<int>(res, a.size() - 1 - last);
        
        return res;
    }
};