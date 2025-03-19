class Solution {
public:
    int numOfUnplacedFruits(vector<int> &a, vector<int> &b) {
        int res = 0;
        for (int aValue : a) {
            bool found = 0;
            for (int &bValue : b) {
                if (bValue >= aValue) {
                    bValue = 0;
                    found = 1;
                    break;
                }
            }
            res += !found;
        }
        return res;
    }
};