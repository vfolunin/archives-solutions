class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<int> index(1 << w, -1);
        for (int y = 0; y < h; y++) {
            int mask = 0;
            for (int x = 0; x < w; x++)
                mask |= a[y][x] << x;
            index[mask] = y;
        }
        
        if (index[0] != -1)
            return { index[0] };
        
        for (int i = 0; i < index.size(); i++) {
            if (index[i] == -1)
                continue;
            
            for (int j = 0; j < index.size(); j++) {
                if (index[j] == -1 || (i & j))
                    continue;

                vector<int> res = { index[i], index[j] };
                if (res[0] > res[1])
                    swap(res[0], res[1]);
                return res;
            }
        }
        
        return {};
    }
};