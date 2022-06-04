class Solution {
public:
    string tictactoe(vector<vector<int>> &moves) {
        vector<vector<int>> a(3, vector<int>(3));
        for (int i = 0; i < moves.size(); i++)
            a[moves[i][0]][moves[i][1]] = i % 2 + 1;
        
        for (int i = 0; i < 3; i++) {
            if (a[i][0] && a[i][0] == a[i][1] && a[i][0] == a[i][2])
                return a[i][0] == 1 ? "A" : "B";
            if (a[0][i] && a[0][i] == a[1][i] && a[0][i] == a[2][i])
                return a[0][i] == 1 ? "A" : "B";
        }
        if (a[0][0] && a[0][0] == a[1][1] && a[0][0] == a[2][2])
            return a[0][0] == 1 ? "A" : "B";
        if (a[0][2] && a[0][2] == a[1][1] && a[0][2] == a[2][0])
            return a[0][2] == 1 ? "A" : "B";
        
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};