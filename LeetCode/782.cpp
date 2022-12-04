class Solution {
public:
    int movesToChessboard(vector<vector<int>> &a) {
        if (abs(count(a[0].begin(), a[0].end(), 0) - count(a[0].begin(), a[0].end(), 1)) > 1)
            return -1;
        
        map<vector<int>, int> count;
        for (vector<int> &row : a)
            count[row]++;
        if (count.size() != 2 || abs(count.begin()->second - count.rbegin()->second) > 1)
            return -1;
        
        for (int x = 0; x < a.size(); x++)
            if (count.begin()->first[x] == count.rbegin()->first[x])
                return -1;        
        
        int badRowCount = 0;
        for (int y = 0; y < a.size(); y++)
            badRowCount += a[y][0] != y % 2;
        
        if (badRowCount % 2 || a.size() % 2 == 0 && badRowCount > a.size() - badRowCount)
            badRowCount = a.size() - badRowCount;
        
        int badColCount = 0;
        for (int x = 0; x < a.size(); x++)
            badColCount += a[0][x] != x % 2;
        
        if (badColCount % 2 || a.size() % 2 == 0 && badColCount > a.size() - badColCount)
            badColCount = a.size() - badColCount;
        
        return (badRowCount + badColCount) / 2;
    }
};