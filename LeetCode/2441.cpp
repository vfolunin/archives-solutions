class Solution {
public:
    int findMaxK(vector<int> &a) {
        sort(a.begin(), a.end());
        
        for (int i = a.size() - 1; i >= 0 && a[i] > 0; i--)
            if (binary_search(a.begin(), a.end(), -a[i]))
                return a[i];
        
        return -1;
    }
};