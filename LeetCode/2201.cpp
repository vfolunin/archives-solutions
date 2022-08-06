class Solution {    
public:
    int digArtifacts(int size, vector<vector<int>> &artifacts, vector<vector<int>> &dig) {
        vector<vector<int>> a(size, vector<int>(size));
        vector<int> aSize(artifacts.size() + 1);
        
        for (int i = 0; i < artifacts.size(); i++) {
            for (int y = artifacts[i][0]; y <= artifacts[i][2]; y++) {
                for (int x = artifacts[i][1]; x <= artifacts[i][3]; x++) {
                    a[y][x] = i + 1;
                    aSize[i + 1]++;
                }
            }
        }
        
        for (vector<int> &cell : dig)
            aSize[a[cell[0]][cell[1]]]--;

        return count(aSize.begin() + 1, aSize.end(), 0);
    }
};