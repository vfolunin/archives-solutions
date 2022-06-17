class Solution {
    void twoSum(vector<int> &a, int from, vector<vector<int>> &triplets) {
        for (int l = from + 1, r = a.size() - 1; l < r; l++) {
            while (l < r && a[from] + a[l] + a[r] > 0)
                r--;
            if (l < r && a[from] + a[l] + a[r] == 0) {
                vector<int> triplet = { a[from], a[l], a[r] };
                if (triplets.empty() || triplets.back() != triplet)
                    triplets.push_back(triplet);
            }                    
        }
    }
    
public:
    vector<vector<int>> threeSum(vector<int> &a) {
        sort(a.begin(), a.end());
        
        vector<vector<int>> triplets;
        for (int i = 0; i + 2 < a.size(); i++)
            if (!i || a[i - 1] != a[i])
                twoSum(a, i, triplets);
        return triplets;
    }
};