class Solution {
    int getCount(vector<string> &a, char c) {
        int res = 0;
        for (string &row : a)
            res += count(row.begin(), row.end(), c);
        return res;
    }
    
    bool wins(vector<string> &a, char c) {
        for (int i = 0; i < 3; i++)
            if (a[i][0] == c && a[i][1] == c && a[i][2] == c ||
                a[0][i] == c && a[1][i] == c && a[2][i] == c)
                return 1;
        
        return a[0][0] == c && a[1][1] == c && a[2][2] == c ||
               a[0][2] == c && a[1][1] == c && a[2][0] == c;
    }
    
public:
    bool validTicTacToe(vector<string> &a) {
        int xCount = getCount(a, 'X'), oCount = getCount(a, 'O');
        
        if (xCount == oCount)
            return !wins(a, 'X');
        else if (xCount == oCount + 1)
            return !wins(a, 'O');
        else
            return 0;
    }
};