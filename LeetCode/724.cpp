class Solution {
public:
    int pivotIndex(vector<int> &a) {
        int lSum = 0, rSum = 0;
        for (int value : a)
            rSum += value;
        
        for (int i = 0; i < a.size(); i++) {
            rSum -= a[i];
            if (lSum == rSum)
                return i;
            lSum += a[i];
        }
        
        return -1;
    }
};