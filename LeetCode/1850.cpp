class Solution {
public:
    int getMinSwaps(string &a, int k) {
        string b = a;
        for (int i = 0; i < k; i++)
            next_permutation(b.begin(), b.end());
        
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            int j = find(a.begin() + i, a.end(), b[i]) - a.begin();
            while (i < j) {
                swap(a[j], a[j - 1]);
                j--;
                res++;
            }
        }
        
        return res;
    }
};