class Solution {
public:
    int isWinner(vector<int> &a, vector<int> &b) {
        int aScore = 0, bScore = 0;

        for (int i = 0; i < a.size(); i++) {
            aScore += a[i];
            if (i >= 1 && a[i - 1] == 10 || i >= 2 && a[i - 2] == 10)
                aScore += a[i];

            bScore += b[i];
            if (i >= 1 && b[i - 1] == 10 || i >= 2 && b[i - 2] == 10)
                bScore += b[i];
        }

        if (aScore == bScore)
            return 0;
        else if (aScore > bScore)
            return 1;
        else
            return 2;
    }
};