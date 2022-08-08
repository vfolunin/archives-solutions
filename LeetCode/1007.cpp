class Solution {
public:
    int minDominoRotations(vector<int> &a, vector<int> &b) {
        int res = 1e9;
        
        for (int value = 1; value <= 6; value++) {
            int aScore = 0, bScore = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != value) {
                    if (b[i] == value)  
                        aScore++;
                    else
                        aScore = 1e9;
                }
                if (b[i] != value) {
                    if (a[i] == value)  
                        bScore++;
                    else
                        bScore = 1e9;
                }
            }
            res = min({ res, aScore, bScore });
        }
        
        return (res != 1e9 ? res : -1);
    }
};