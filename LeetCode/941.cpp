class Solution {
public:
    bool validMountainArray(vector<int> &a) {
        if (a.size() < 3)
            return 0;
        
        int m = max_element(a.begin(), a.end()) - a.begin();
        if (m == 0 || m == a.size() - 1)
            return 0;
        
        for (int i = 0; i < m; i++)
            if (a[i] >= a[i + 1])
                return 0;
        
        for (int i = m + 1; i < a.size(); i++)
            if (a[i - 1] <= a[i])
                return 0;
        
        return 1;
    }
};