class Solution {
public:
    bool canPlaceFlowers(vector<int> &a, int n) {
        a.insert(a.begin(), 0);
        a.push_back(0);
        
        int row = 0;
        for (int value : a) {
            if (!value) {
                row++;
            } else {
                n -= (row - 1) / 2;
                row = 0;
            }
        }
        n -= (row - 1) / 2;
        
        return n <= 0;
    }
};