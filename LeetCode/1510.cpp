class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> win(n + 1);
        
        for (int i = 1; i < win.size(); i++) {
            for (int j = 1; j * j <= i; j++) {
                if (!win[i - j * j]) {
                    win[i] = 1;
                    break;
                }
            }
        }
        
        return win.back();
    }
};