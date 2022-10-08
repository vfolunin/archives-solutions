class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>> &segments) {
        sort(segments.begin(), segments.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        vector<int> res;
        
        for (vector<int> &segment : segments) {
            int count = res.end() - lower_bound(res.begin(), res.end(), segment[0]);

            if (count == 0) {
                int x = segment[1];
                while (binary_search(res.begin(), res.end(), x))
                    x--;

                res.push_back(x);
                int i = res.size() - 1;
                while (i && res[i - 1] > res[i]) {
                    swap(res[i - 1], res[i]);
                    i--;
                }
            }

            if (count <= 1) {
                int x = segment[1];
                while (binary_search(res.begin(), res.end(), x))
                    x--;

                res.push_back(x);
                int i = res.size() - 1;
                while (i && res[i - 1] > res[i]) {
                    swap(res[i - 1], res[i]);
                    i--;
                }
            }
        }
        
        return res.size();
    }
};