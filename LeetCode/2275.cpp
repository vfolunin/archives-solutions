class Solution {
public:
    int largestCombination(vector<int> &a) {
        vector<int> count(32);
        
        for (int value : a) {
            for (int bit = 0; bit < 32; bit++) {
                count[bit] += value % 2;
                value /= 2;
            }
        }
        
        return *max_element(count.begin(), count.end());
    }
};