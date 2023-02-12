class Solution {
public:
    int maxBoxesInWarehouse(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        
        vector<int> bl = b;
        for (int i = 1; i < bl.size(); i++)
            bl[i] = min(bl[i], bl[i - 1]);

        vector<int> br = b;
        for (int i = (int)br.size() - 2; i >= 0; i--)
            br[i] = min(br[i], br[i + 1]);

        for (int i = 0; i < b.size(); i++)
            b[i] = max(bl[i], br[i]);
        
        sort(b.begin(), b.end());

        int ai = 0;
        for (int bi = 0; ai < a.size() && bi < b.size(); bi++)
            ai += a[ai] <= b[bi];
        return ai;
    }
};