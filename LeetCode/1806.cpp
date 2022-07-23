class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        
        int res = 0;
        
        do {
            vector<int> b(n);
            for (int i = 0; i < n; i++)
                b[i] = a[i % 2 ? n / 2 + i / 2 : i / 2];
            a.swap(b);
            res++;
        } while (!is_sorted(a.begin(), a.end()));
        
        return res;
    }
};