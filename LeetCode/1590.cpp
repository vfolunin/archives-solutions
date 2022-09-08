class Solution {
public:
    int minSubarray(vector<int> &a, int divisor) {
        int totalMod = 0;
        for (int value : a)
            totalMod = (totalMod + value) % divisor;
        
        if (!totalMod)
            return 0;
        
        unordered_map<int, int> last = { { 0, -1 } };
        int prefixMod = 0, res = a.size();
        
        for (int i = 0; i < a.size(); i++) {
            prefixMod = (prefixMod + a[i]) % divisor;
            int otherMod = ((prefixMod - totalMod) % divisor + divisor) % divisor;
            if (last.count(otherMod))
                res = min(res, i - last[otherMod]);
            last[prefixMod] = i;                
        }
        
        return res != a.size() ? res : -1;
    }
};