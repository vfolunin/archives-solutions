class Solution {
public:
    bool winnerOfGame(string &s) {
        vector<int> score(2);
        
        int row = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                row++;
            } else {
                score[s[i - 1] - 'A'] += max(0, row - 2);
                row = 1;
            }
        }
        score[s.back() - 'A'] += max(0, row - 2);
        
        return score[0] > score[1];
    }
};