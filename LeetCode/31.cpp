class Solution {
public:
    void nextPermutation(vector<int> &a) {
        int i = (int)a.size() - 2;
        while (i >= 0 && a[i] >= a[i + 1])
            i--;
        
        if (i < 0) {
            reverse(a.begin(), a.end());
            return;
        }
        
        int j = a.size() - 1;
        while (a[i] >= a[j])
            j--;
        
        swap(a[i], a[j]);
        reverse(a.begin() + i + 1, a.end());
    }
};