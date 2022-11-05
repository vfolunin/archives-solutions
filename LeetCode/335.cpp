class Solution {
public:
    bool isSelfCrossing(vector<int> &a) {
        for (int i = 3; i < a.size(); i++)
            if (a[i - 3] >= a[i - 1] && a[i - 2] <= a[i])
                return 1;
        
        for (int i = 4; i < a.size(); i++)
            if (a[i - 3] == a[i - 1] && a[i - 2] <= a[i - 4] + a[i])
                return 1;
        
        for (int i = 5; i < a.size(); i++)
            if (a[i - 4] <= a[i - 2] && a[i - 3] >= a[i - 1] &&
                a[i - 3] <= a[i - 5] + a[i - 1] && a[i - 2] <= a[i - 4] + a[i])
                return 1;
        
        return 0;
    }
};