class Solution {
public:
    int minimumDeletions(vector<int> &a) {
        int l = min_element(a.begin(), a.end()) - a.begin();
        int r = max_element(a.begin(), a.end()) - a.begin();
        if (l > r)
            swap(l, r);
        
        return min(r + 1, min<int>(a.size() - l, l + 1 + a.size() - r));
    }
};