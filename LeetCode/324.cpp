class Solution {
public:
    void wiggleSort(vector<int> &a) {
        auto b = a;
        sort(b.begin(), b.end());
        
        int l = (b.size() - 1) / 2, r = b.size() - 1;
        for (int i = 0; i < a.size(); i++) {
            if (i % 2 == 0)
                a[i] = b[l--];
            else
                a[i] = b[r--];
        }
    }
};