class Solution {
public:
    vector<int> fairCandySwap(vector<int> &a, vector<int> &b) {
        int aSum = 0;
        for (int value : a)
            aSum += value;
        
        int bSum = 0;
        for (int value : b)
            bSum += value;
        
        int delta = bSum - aSum;
        sort(b.begin(), b.end());
        
        for (int aValue : a) {
            int bValue = aValue + delta / 2;
            if (binary_search(b.begin(), b.end(), bValue))
                return { aValue, bValue };
        }
        
        return {};
    }
};