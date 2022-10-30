class Solution {
public:
    int averageValue(vector<int> &a) {
        int sum = 0, count = 0;
        
        for (int &value : a) {
            if (value % 6 == 0) {
                sum += value;
                count++;
            }
        }
        
        return count ? sum / count : 0;
    }
};