class Solution {
public:
    vector<vector<int>> generate(int rowCount) {
        vector<vector<int>> a(rowCount);
        a[0] = { 1 };
        
        for (int i = 1; i < rowCount; i++) {
            a[i].resize(i + 1);
            a[i][0] = a[i][i] = 1;
            for (int j = 1; j < i; j++)
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
        
        return a;
    }
};