class Solution {
    bool check(vector<vector<int>> &a, int y, int x, int size) {
        int targetSum = 0;
        for (int i = 0; i < size; i++)
            targetSum += a[y + i][x + i];
        
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += a[y + i][x + size - 1 - i];
        if (sum != targetSum)
            return 0;
        
        for (int i = 0; i < size; i++) {
            sum = 0;
            for (int j = 0; j < size; j++)
                sum += a[y + i][x + j];
            if (sum != targetSum)
                return 0;
        }
        
        for (int j = 0; j < size; j++) {
            sum = 0;
            for (int i = 0; i < size; i++)
                sum += a[y + i][x + j];
            if (sum != targetSum)
                return 0;
        }
        
        return 1;
    }
    
public:
    int largestMagicSquare(vector<vector<int>> &a) {
        for (int size = min(a.size(), a[0].size()); size; size--)
            for (int y = 0; y + size <= a.size(); y++)
                for (int x = 0; x + size <= a[0].size(); x++)
                    if (check(a, y, x, size))
                        return size;
        return 0;
    }
};