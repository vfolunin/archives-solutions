class Solution {
public:
    int maxLength(vector<string> &a) {
        vector<int> valueMasks(a.size());
        for (int i = 0; i < a.size(); i++) {
            for (char c : a[i]) {
                if (valueMasks[i] & (1 << (c - 'a'))) {
                    valueMasks[i] = -1;
                    break;
                }
                valueMasks[i] |= 1 << (c - 'a');
            }
        }
        
        int res = 0;
        
        for (int mask = 0; mask < (1 << a.size()); mask++) {
            int valueMask = 0, size = 0;
            for (int bit = 0; bit < a.size(); bit++) {
                if (mask & (1 << bit)) {
                    if (valueMasks[bit] == -1 || (valueMask & valueMasks[bit])) {
                        valueMask = -1;
                        break;
                    }
                    valueMask |= valueMasks[bit];
                    size += a[bit].size();
                }
            }
            if (valueMask != -1)
                res = max(res, size);
        }
        
        return res;
    }
};