class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &a) {
        unordered_map<int, vector<int>> diag;
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a.size(); x++)
                diag[y - x].push_back(a[y][x]);
        
        for (auto &[d, values] : diag) {
            if (d < 0)
                sort(values.begin(), values.end());
            else
                sort(values.rbegin(), values.rend());
        }

        for (int y = a.size() - 1; y >= 0; y--) {
            for (int x = a.size() - 1; x >= 0; x--) {
                a[y][x] = diag[y - x].back();
                diag[y - x].pop_back();
            }
        }
        return a;
    }
};