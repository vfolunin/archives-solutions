class Solution {
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b) { return a[1] > b[1]; });
        
        int res = 0;
        for (vector<int> &boxType : boxTypes) {
            int count = min(boxType[0], truckSize);
            res += count * boxType[1];
            truckSize -= count;
        }
        
        return res;
    }
};