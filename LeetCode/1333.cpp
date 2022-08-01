class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>> &a, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> res;
        
        for (int i = 0; i < a.size(); i++)
            if ((!veganFriendly || a[i][2]) && a[i][3] <= maxPrice && a[i][4] <= maxDistance)
                res.push_back(i);
        
        sort(res.begin(), res.end(), [&](int i, int j) {
            if (a[i][1] != a[j][1])
                return a[i][1] > a[j][1];
            return a[i][0] > a[j][0];
        });
        
        for (int &i : res)
            i = a[i][0];
        
        return res;
    }
};