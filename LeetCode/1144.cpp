class Solution {
public:
    int movesToMakeZigzag(vector<int> &a) {
        int evenRes = 0;
        for (int i = 0; i < a.size(); i += 2) {
            int l = i ? a[i - 1] : 1001;
            int r = i + 1 < a.size() ? a[i + 1] : 1001;
            int value = min(l, r) - 1;
            evenRes += max(0, a[i] - value);
        }
        
        int oddRes = 0;
        for (int i = 1; i < a.size(); i += 2) {
            int l = i ? a[i - 1] : 1001;
            int r = i + 1 < a.size() ? a[i + 1] : 1001;
            int value = min(l, r) - 1;
            oddRes += max(0, a[i] - value);
        }
        
        return min(evenRes, oddRes);
    }
};