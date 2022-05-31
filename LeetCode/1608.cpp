class Solution {
public:
    int specialArray(vector<int> &a) {
        sort(a.begin(), a.end());
        
        int l = -1, r = a.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            
            if (a.end() - lower_bound(a.begin(), a.end(), m) > m)
                l = m;
            else
                r = m;
        }
        
        return a.end() - lower_bound(a.begin(), a.end(), r) == r ? r : -1;
    }
};class Solution {
public:
    int specialArray(vector<int> &a) {
        sort(a.begin(), a.end());
        
        int l = -1, r = a.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            
            if (a.end() - lower_bound(a.begin(), a.end(), m) > m)
                l = m;
            else
                r = m;
        }
        
        return a.end() - lower_bound(a.begin(), a.end(), r) == r ? r : -1;
    }
};