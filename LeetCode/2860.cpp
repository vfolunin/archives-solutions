class Solution {
public:
    int countWays(vector<int> &a) {
        sort(a.begin(), a.end());
        
        int res = 0 < a[0];
        
        for (int selected = 1; selected < a.size(); selected++)
            res += a[selected - 1] < selected && selected < a[selected];
        
        res += a.back() < a.size();
        
        return res;
    }
};