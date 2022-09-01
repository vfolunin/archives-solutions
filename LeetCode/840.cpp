class Solution {
    bool isMagic(vector<vector<int>> &a, int y, int x) {
        vector<int> used(16);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                used[a[y + i][x + j]] = 1;
        
        if (count(used.begin() + 1, used.begin() + 10, 1) != 9)
            return 0;
        
        int targetSum = 0;
        for (int i = 0; i < 3; i++)
            targetSum += a[y + i][x + i];
        
        int sum = 0;
        for (int i = 0; i < 3; i++)
            sum += a[y + i][x + 2 - i];
        if (sum != targetSum)
            return 0;
        
        for (int i = 0; i < 3; i++) {
            sum = 0;
            for (int j = 0; j < 3; j++)
                sum += a[y + i][x + j];
            if (sum != targetSum)
                return 0;
            
            sum = 0;
            for (int j = 0; j < 3; j++)
                sum += a[y + j][x + i];
            if (sum != targetSum)
                return 0;
        }
        
        return 1;
    }
    
public:
    int numMagicSquaresInside(vector<vector<int>> &a) {
        int res = 0;
        
        for (int y = 0; y + 3 <= a.size(); y++)
            for (int x = 0; x + 3 <= a[0].size(); x++)
                res += isMagic(a, y, x);
        
        return res;
    }
};