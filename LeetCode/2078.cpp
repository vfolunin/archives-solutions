class Solution {
public:
    int maxDistance(vector<int> &a) {
        int l = 0;
        while (a[l] == a.back())
            l++;
        
        int r = a.size() - 1;
        while (a[0] == a[r])
            r--;
        
        return max<int>(a.size() - 1 - l, r);
    }
};