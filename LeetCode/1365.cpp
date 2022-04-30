class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &a) {
        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());
        
        for (int &value : a)
            value = lower_bound(sortedA.begin(), sortedA.end(), value) - sortedA.begin();
        return a;
    }
};